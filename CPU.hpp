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

#include 				"Lexer.hpp"
#include 				"eOperand.hpp"
#include 				"Factory.hpp"


//TODO: Your machine must be able to run programs from a file passed as a parameter and from the standard input. When reading from the standard input, the end of the program is indicated by the special symbol ";;" otherwise absent.
// -DBL/float_MAX
// long double;
// stdint
// float
// 1. static cast for the string value, 2. do smth - check Pasha method;

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
		void _execute_inner_logic				( const int quantity_of_arguments, char * argument );
		bool _print								( void );
		void _exit								( void );
};

#endif
