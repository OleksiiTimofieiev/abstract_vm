#ifndef	CPU_HPP
#define CPU_HPP

#define output(x) std::cout << (x) << std::endl;
// output with color;

#include <vector>
#include <functional>
#include <iostream>
#include <typeinfo>
#include <stdio.h>

#include "Lexer.hpp"
#include "eOperand.hpp"
#include "Factory.hpp"

# define RED   			"\x1B[31m"
# define COLOR_RESET 	"\x1B[0m"

//TODO:make full documentation for the each class;
//TODO:copl form for each class;

//TODO:vector of objects: eNum command, eNum type, eNum value;

class	CPU
{
	private:
		Parser 									_parser;
		Lexer 									_lexer;
		// eOperand<char> 							_eOperand; factory class will retun it; delete it ?
		// Factory									_factory;			
		std::vector<std::vector<std::string> > 	_command_list;
		std::vector<IOperand const *> 			_stack;

		void _commands_execution_routine								( void );



	public:
		CPU										( void );
		~CPU									( void );

		// magic ;)
		void execute_inner_logic				( const int quantity_of_arguments, char * argument );
		bool print								( void );
		void _exit								( void );

};

#endif
