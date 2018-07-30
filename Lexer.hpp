#ifndef LEXER_HPP
#define LEXER_HPP

#include "Parser.hpp"
#include "Exception.hpp"

//TODO: add complien form;

class Lexer
{
	public:
		Lexer				( void );
		~Lexer				( void );

		bool				regex_checks( std::string str, std::vector<std::vector<std::string> > &_command_list );
		void				lexical_analysis( Parser &parser, std::vector<std::vector<std::string> > &_command_list );
};

#endif
