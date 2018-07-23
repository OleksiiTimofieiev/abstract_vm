#include "CPU.hpp"

CPU::CPU () {}
CPU::~CPU() {}

void	CPU::execute_inner_logic( const int quantity_of_arguments, char *argument )
{
	_parser.read(quantity_of_arguments, argument);

	//FIXME: delete the stuff below in the end of the project;

	_parser.print_list();
	_parser.detect_leaks();
}
