#include "Lexer.hpp"
#include <regex>
#include <iostream>

Lexer::Lexer() {}
Lexer::~Lexer() {}

//TODO: add copliens form;

bool	Lexer::regex_checks( std::string str )
{
	bool flag = false;

	const std::regex regular_expression_for_commands_without_arguments("^(pop|dump|add|sub|mul|div|mod|print|exit|;;)\\s*$");
	const std::regex regular_expression_for_commands_with_arguments_int("^(push|assert) (int8|int16|int32)(\\()([-]?[0-9]+)(\\))\\s*$");
	const std::regex regular_expression_for_commands_with_arguments_float_double("^(push|assert) (float|double)(\\()([-]?[0-9]+)(\\.)[0-9]+(\\))\\s*$");

	if (std::regex_match(str, regular_expression_for_commands_without_arguments))
		flag = true;
	else if ((std::regex_match(str, regular_expression_for_commands_with_arguments_int)))
		flag = true;
	else if ((std::regex_match(str, regular_expression_for_commands_with_arguments_float_double)))
		flag = true;
	return (flag);
}

void	Lexer::lexical_analysis(Parser &parser)
{
	std::cout << std::endl;

	if ( !parser._filtered_input.empty() )
	{
		for ( auto i = parser._filtered_input.begin(); i != parser._filtered_input.end(); ++i )
		{
			static int line = 0;

			line++;
			
			try
			{
				if (!regex_checks( *i ))
				{
					throw_line("invalid line", line);
				}
				else
					std::cout << *i << std::endl;
			}
			catch (const std::runtime_error &ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
	}
}
