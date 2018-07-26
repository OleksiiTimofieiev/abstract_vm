#include "CPU.hpp"

CPU::CPU () {}
CPU::~CPU() {}

//TODO: add copliens form;

void	CPU::execute_inner_logic( const int quantity_of_arguments, char *argument )
{
	_parser.read( quantity_of_arguments, argument );
	_lexer.lexical_analysis( _parser );













	// _parser.detect_leaks(); // detect leaks;
}
