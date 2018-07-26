#ifndef LEXER_HPP
#define LEXER_HPP

#include "Parser.hpp"

class Lexer
{
	public:
		Lexer				( void );
		~Lexer				( void );

		bool				regex_checks( std::string str );
		void 				lexical_analysis (Parser &parser );
};









#endif
