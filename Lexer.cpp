#include "Lexer.hpp"
#include <regex>
#include <iostream>

Lexer::Lexer() {}
Lexer::~Lexer() {}

//TODO: add copliens form;

bool	Lexer::regex_checks( std::string str )
{
	bool flag = false;

	// regex cmatch;
	// std::regex regular_decimal("^\\s*(\\bpush|assert\\b)\\s+(int[8,16,32]{1}\\b)\\(([-]?\\d+)\\)\\s*(;\\w+)?");
	// std::regex regulear_float("^\\s*(\\bpush|assert\\b)\\s+(float|double)\\(([-]?\\d+\\.\\d+)\\)\\s*(;\\w+)?");

	// realization according to the subject grammar section;

	const std::regex regular_expression_for_commands_without_arguments("^(pop|dump|add|sub|mul|div|mod|print|exit|;;)$");
	const std::regex regular_expression_for_commands_with_arguments_int("^(push|assert) (int8|int16|int32)\\(([-]?[0-9]+)\\)$");
	const std::regex regular_expression_for_commands_with_arguments_float_double("^(push|assert) (float|double)\\(([-]?[0-9]+\\.[0-9]+)\\)$");

	if (std::regex_match(str, regular_expression_for_commands_without_arguments))
		flag = true;
	else if ((std::regex_match(str, regular_expression_for_commands_with_arguments_int)))
		flag = true;
	else if ((std::regex_match(str, regular_expression_for_commands_with_arguments_float_double)))
		flag = true;
		
	return (flag);
}

void	Lexer::lexical_analysis( Parser &parser )
{
	std::cout << std::endl;
	int line = 0;

	if ( !parser._filtered_input.empty() )
	{
		for ( auto i = parser._filtered_input.begin(); i != parser._filtered_input.end(); ++i )
		{
			++line; // variable -> line of the errored which occured;
		
			try
			{
				if ( !regex_checks( *i ) )
					throw_line("\033[1;31mLexical error -> \033[0m", line);
			}
			catch ( const std::runtime_error &ex )
			{
				std::cout << ex.what() << std::endl;
			}
		}
	}
}
