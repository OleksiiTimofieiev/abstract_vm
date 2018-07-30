#include "Lexer.hpp"
#include "CPU.hpp"
#include <regex>
#include <string>
#include <iostream>

Lexer::Lexer() {}
Lexer::~Lexer() {}

//TODO: add copliens form;

bool Lexer::regex_checks(std::string str, std::vector<std::vector<std::string> > &_command_list)
{
	bool flag = false;

	int nNumColumns = 3;

	// regex cmatch;
	// std::regex regular_decimal("^\\s*(\\bpush|assert\\b)\\s+(int[8,16,32]{1}\\b)\\(([-]?\\d+)\\)\\s*(;\\w+)?");
	// std::regex regulear_float("^\\s*(\\bpush|assert\\b)\\s+(float|double)\\(([-]?\\d+\\.\\d+)\\)\\s*(;\\w+)?");

	const std::regex commands_without_arguments("^(pop|dump|add|sub|mul|div|mod|print|exit|;;)$");
	const std::regex commands_with_arguments_int("^(push|assert) (int8|int16|int32)\\(([-]?[0-9]+)\\)$");
	const std::regex commands_with_arguments_float_double("^(push|assert) (float|double)\\(([-]?[0-9]+\\.[0-9]+)\\)$");
	
	std::cmatch	result;

	if (std::regex_match( str.c_str(), result, commands_without_arguments) )
	{
		//FIXME:comment in the end of the project
		// for (unsigned int i = 0; i < result.size(); i++) // for diagnostics
		// 	std::cout << result[i] << std::endl;

			std::vector<std::string> lstTableRow;

			lstTableRow.push_back(result[1]);

			for (int j = 1; j < nNumColumns; j++)
				lstTableRow.push_back("No data");
			_command_list.push_back(lstTableRow);

			flag = true;
	}
	else if ((std::regex_match(str.c_str(), result, commands_with_arguments_int)))
	{
		//FIXME:comment in the end of the project
		// for (unsigned int i = 0; i < result.size(); i++) // for diagnostics
		// 	std::cout << result[i] << std::endl;

		std::vector<std::string> lstTableRow;

		for (int j = 0; j < nNumColumns; j++)
			lstTableRow.push_back(result[j + 1]);
		_command_list.push_back(lstTableRow);

		flag = true;
	}
	else if ((std::regex_match( str.c_str(), result, commands_with_arguments_float_double)))
	{
		//FIXME:comment in the end of the project
		// for (unsigned int i = 0; i < result.size(); i++) // for diagnostics
		// 	std::cout << result[i] << std::endl;

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
	output("");
	int line = 0;

	if (!parser._filtered_input.empty())
	{
		for ( auto i = parser._filtered_input.begin(); i != parser._filtered_input.end(); ++i )
		{
			++line; // variable -> line of the errored which occured;
		
			try
			{
				if ( !regex_checks( *i, _command_list ) )
					throw_line("\033[1;31mLexical error -> \033[0m", line);
			}
			catch ( const std::runtime_error &ex )
			{
				std::cout << ex.what() << std::endl;
			}
		}
	}
	output("");
}
