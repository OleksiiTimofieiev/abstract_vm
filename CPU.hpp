# ifndef CPU_HPP
# define CPU_HPP

# define RED   			"\033[1;31m"
# define MAGENTA		"\x1B[35m"	
# define CYAN   		"\x1B[36m"
# define COLOR_RESET 	"\x1B[0m"

# define OUTPUT(x) 		std::cout << (x) << std::endl;
# define OUTPUT_RED(x) 	std::cout << RED << (x) << COLOR_RESET << std::endl;
# define OUTPUT_CYAN(x) std::cout << CYAN << (x) << COLOR_RESET << std::endl;

#include 				<vector>
#include 				<functional>
#include 				<iostream>
#include 				<typeinfo>
#include 				<stdio.h>
#include				<iterator>

#include 				"Lexer.hpp"
#include 				"eOperand.hpp"
#include 				"Factory.hpp"
#include				"Exception.hpp"

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
		void _pop								( int line );
		void _dump								( int line  );
		void _add								( int line );
		void _sub								( int line );
		void _mul								( int line );
		void _div								( int line );
		void _mod								( int line );
		void _print								( int line );
		void _exit								( void );
		void _execute_inner_logic				( const int quantity_of_arguments, char * argument );
};

#endif
