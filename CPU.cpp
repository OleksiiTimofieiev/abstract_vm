#include "CPU.hpp"

CPU::CPU () {}
CPU::~CPU() {}

//TODO: add copliens form;

void CPU::execute_inner_logic(const int quantity_of_arguments, char *argument)
{
	_parser.read( quantity_of_arguments, argument );
	_lexer.lexical_analysis( _parser, _command_list );

	std::cout << _command_list[0][0] << std::endl;
	std::cout << _command_list[0][1] << std::endl;
	std::cout << _command_list[0][2] << std::endl;
	std::cout << _command_list[0][3] << std::endl;

	std::cout << _command_list[1][0] << std::endl;
	std::cout << _command_list[1][1] << std::endl;
	std::cout << _command_list[1][2] << std::endl;
	std::cout << _command_list[1][3] << std::endl;

	_parser.detect_leaks(); // detect leaks;
}
