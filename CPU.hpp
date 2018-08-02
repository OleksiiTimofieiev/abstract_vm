# ifndef CPU_HPP
# define CPU_HPP

# define RED   			"\033[1;31m"
# define MAGENTA		"\x1B[35m"	
# define COLOR_RESET 	"\x1B[0m"

# define OUTPUT_RED(x) 	std::cout << RED << (x) << COLOR_RESET << std::endl;
# define OUTPUT(x) 		std::cout << (x) << std::endl;

#include 				<vector>
#include 				<functional>
#include 				<iostream>
#include 				<typeinfo>
#include 				<stdio.h>
#include				<iterator>

#include 				"Lexer.hpp"
#include 				"eOperand.hpp"
#include 				"Factory.hpp"


// • Overflow on a value
// • Underflow on a value
// • Instruction pop on an empty stack
// • Division/modulo by 0
// • The program doesn’t have an exit instruction
// • An assert instruction is not true
// • The stack is composed of strictly less that two values when an arithmetic instruction is executed.

// -DBL/float_MAX
// long double;
// stdint
// float
// 1. static cast for the string value, 2. do smth - check Pasha method;
// cast to the bigger value, even assert;
// make cool makefile;

class	CPU
{
	private:
		Parser 									_parser;
		Lexer 									_lexer;
		Factory									_factory;			
		std::vector<std::vector<std::string> > 	_command_list;
		std::vector<IOperand const *> 			_stack;
		void _commands_execution_routine		( void );

	public:
		CPU										( void );
		~CPU									( void );
		CPU &operator =							( CPU const &rhs );
		CPU										( CPU const &src );
		void _push								( std::string Type, std::string value);
		void _execute_inner_logic				( const int quantity_of_arguments, char * argument );
		bool _print								( void );
		void _exit								( void );
};

#endif
