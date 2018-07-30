#include "CPU.hpp"

CPU::CPU () {}
CPU::~CPU() {}

//TODO: add copliens form;

void CPU::execute_inner_logic(const int quantity_of_arguments, char *argument)
{
	_parser.read			( quantity_of_arguments, argument );
	_lexer.lexical_analysis	( _parser, _command_list );

	// output(_command_list[0][0]);
	// output(_command_list[0][1]);
	// output(_command_list[0][2]);
	// output("");

	// output(_command_list[1][0]);
	// output(_command_list[1][1]);
	// output(_command_list[1][2]);
	// output("");

	// output(_command_list[2][0]);
	// output(_command_list[2][1]);
	// output(_command_list[2][2]);
	// output("");

	_parser.detect_leaks(); // detect leaks;
}
