#ifndef	INCLUDES_HPP
#define	INCLUDES_HPP

/* ********************* colors ********************* */

# define RED   			"\033[1;31m"
# define MAGENTA		"\x1B[35m"	
# define CYAN   		"\x1B[36m"
# define COLOR_RESET 	"\x1B[0m"

/* ********************* output defines ********************* */

# define OUTPUT(x) 		std::cout << (x) << std::endl;
# define OUTPUT_RED(x) 	std::cout << RED << (x) << COLOR_RESET << std::endl;
# define OUTPUT_CYAN(x) std::cout << CYAN << (x) << COLOR_RESET << std::endl;

/* ********************* libs ********************* */

#include 				<vector>
#include 				<functional>
#include 				<iostream>
#include 				<typeinfo>
#include 				<stdio.h>
#include				<iterator>

/* ********************* hpp ********************* */

#include 				"Lexer.hpp"
#include 				"eOperand.hpp"
#include 				"Factory.hpp"
#include				"Exception.hpp"

#endif
