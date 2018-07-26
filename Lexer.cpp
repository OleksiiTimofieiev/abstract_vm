#include "Lexer.hpp"
#include <regex>
#include <iostream>

Lexer::Lexer() {}
Lexer::~Lexer() {}

//TODO: add copliens form;

bool	Lexer::regex_checks( std::string str )
{
	bool flag = false;

	const std::regex regular_expression_for_commands_without_arguments("^(pop|dump|add|sub|mul|div|mod|print|exit|;;)$");
	const std::regex regular_expression_for_commands_with_arguments("^(push|assert)$");
	
	if (std::regex_match(str, regular_expression_for_commands_without_arguments))
		flag = true;
	else if ((std::regex_match(str, regular_expression_for_commands_with_arguments)))
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
			// std::string	test = *i;
			if (!regex_checks( *i ) )
			std::cout << "Unvalid line." << std::endl;
			
		}
	}
	std::cout << std::endl;
}
