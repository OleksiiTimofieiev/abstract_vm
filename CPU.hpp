#ifndef	CPU_HPP
#define CPU_HPP

// my usual defines;
#define output(x) std::cout << (x) << std::endl;

#include "Parser.hpp" // Parser emulation;
#include "Lexer.hpp" // Lexer emulation;
#include <vector>

class	CPU
{
	private:
		Parser 						_parser;
		Lexer 						_lexer;

		std::vector<std::vector<std::string> > _command_list;

		//TODO:create stack and start to work with it;

	public:
		CPU							( void );
		~CPU						( void );

		// magic ;)
		void execute_inner_logic	( const int quantity_of_arguments, char * argument );
};

#endif
