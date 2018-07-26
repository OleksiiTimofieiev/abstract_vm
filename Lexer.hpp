#ifndef LEXER_HPP
#define LEXER_HPP

#include "Parser.hpp"

class Lexer
{
	public:
		Lexer				( void );
		~Lexer				( void );

		void 	lexical_analysis(Parser &parser);
		//TODO: lexer function;
};









#endif
