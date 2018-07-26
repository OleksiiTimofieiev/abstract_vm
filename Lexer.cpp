#include "Lexer.hpp"
#include <regex>
#include <iostream>

Lexer::Lexer() {}
Lexer::~Lexer() {}

//TODO: add copliens form;

void Lexer::lexical_analysis(Parser &parser)
{
	std::cout << std::endl;

	const std::regex regular_expression_for_commands_without_arguments("(pop|dump|add|sub|mul|div|mod|print|exit|;;)");

	if ( !parser._filtered_input.empty() )
	{
		for ( auto i = parser._filtered_input.begin(); i != parser._filtered_input.end(); ++i )
		{
			std::string	test = *i;

			if (!std::regex_match(test, regular_expression_for_commands_without_arguments))
				std::cout << "Unvalid line." << std::endl;
		}
	}
	std::cout << std::endl;
}
