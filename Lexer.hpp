#ifndef LEXER_HPP
#define LEXER_HPP

#include "Parser.hpp"

class Lexer
{
	public:
		Lexer( void );
		~Lexer( void );
		
		void	show_contents(Parser & parser);
};









#endif
