#ifndef	CPU_HPP
#define CPU_HPP

// my usual defines;
#define output(x) std::cout << (x) << std::endl;

#include "Parser.hpp" // Parser emulation;
#include "Lexer.hpp" // Lexer emulation;
#include "eOperand.hpp"
#include "Factory.hpp"
#include <vector>

//TODO:make full documentation for the each class;

class	CPU
{
	private:
		Parser 									_parser;
		Lexer 									_lexer;
		Factory									_factory;				

		std::vector<std::vector<std::string> > 	_command_list;
		std::vector<IOperand const *> 			_stack;


	public:
		CPU										( void );
		~CPU									( void );

		// magic ;)
		void execute_inner_logic				( const int quantity_of_arguments, char * argument );
};

#endif
