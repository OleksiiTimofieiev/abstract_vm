#include "Lexer.hpp"
#include "CPU.hpp"
#include <regex>
#include <string>
#include <iostream>

Lexer::Lexer() {}
Lexer::~Lexer() {}

bool Lexer::regex_checks(std::string str, std::vector<std::vector<std::string> > &_command_list)
{
	bool flag = false;
	int nNumColumns = 3;

	std::smatch		result;
	const 			std::regex	commands_without_arguments("^(pop|dump|add|sub|mul|div|mod|print|exit|;;|max)$");
	const 			std::regex	commands_with_arguments_int("^(push|assert|more|lesser) (int8|int16|int32)\\(([\\-]?[0-9]+)\\)$");
	const 			std::regex	commands_with_arguments_float_double("^(push|assert|more|lesser) (float|double)\\(([\\-]?[0-9]+\\.[0-9]+)\\)$");
	const			std::regex	empty_line("^\\s*$");

	if (std::regex_match( str, result, commands_without_arguments) || std::regex_match( str, result, empty_line))
	{
		std::vector<std::string> lstTableRow;

		lstTableRow.push_back(result[1]);

		for (int j = 1; j < nNumColumns; j++)
			lstTableRow.push_back("No data");
		_command_list.push_back(lstTableRow);

		flag = true;
	}
	else if ((std::regex_match(str, result, commands_with_arguments_int)))
	{
		std::vector<std::string> lstTableRow;

		for (int j = 0; j < nNumColumns; j++)
			lstTableRow.push_back(result[j + 1]);
		_command_list.push_back(lstTableRow);

		flag = true;
	}
	else if ((std::regex_match( str, result, commands_with_arguments_float_double)))
	{
		std::vector<std::string> lstTableRow;

		for (int j = 0; j < nNumColumns; j++)
			lstTableRow.push_back(result[j + 1]);
		_command_list.push_back(lstTableRow);

		flag = true;
	}
	return (flag);
}

void Lexer::lexical_analysis(Parser &parser, std::vector<std::vector<std::string> > &_command_list )
{
	int line = 0;
	bool error = false;

	if (parser._filtered_input.empty())
	{
		OUTPUT_RED("No instructions.");
		exit(0);
	}
	else 
	{
		for (auto i = parser._filtered_input.begin(); i != parser._filtered_input.end(); ++i)
		{
			++line; // variable -> line of the errored which occured;

			try
			{
				if (!regex_checks(*i, _command_list))
				{
					error = true;
					throw_line("\033[1;31mLexical error on line # -> \033[0m", line);
				}
			}
			catch (const std::runtime_error &ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
	}
	if (!error)
		OUTPUT("\033[1;32mNo lexical errors have been detected => [ avm ] ✓\x1B[0m")
}
