#include "Lexer.hpp"

Lexer::Lexer() {}
Lexer::~Lexer() {}

//TODO: add copliens form;

void	Lexer::show_contents( Parser & parser )
{
	if ( !parser._filtered_input.empty() )
	{
		for ( auto i = parser._filtered_input.cbegin(); i != parser._filtered_input.cend(); ++i )
			std::cout << *i << std::endl;
	}
}
