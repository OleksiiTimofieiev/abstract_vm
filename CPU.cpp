#include "CPU.hpp"
#include "Factory.hpp"

CPU::CPU () {}
CPU::~CPU() {}

//TODO: add copliens form;
//TODO: Your machine must be able to run programs from a file passed as a parameter and from the standard input. When reading from the standard input, the end of the program is indicated by the special symbol ";;" otherwise absent.

void	CPU::execute_inner_logic(const int quantity_of_arguments, char *argument)
{
	_parser.read				( quantity_of_arguments, argument );
	_lexer.lexical_analysis		( _parser, _command_list );
	_commands_execution_routine	();
	//FIXME:delete in the end of the project;
	_parser.detect_leaks(); // detect leaks;
}

void	CPU::_commands_execution_routine()
{


	eOperand<int8_t> a("1");
	eOperand<int16_t> b("2");
	eOperand<int32_t> c("3");
	eOperand<float> d("4");
	eOperand<double> e("5");

	// a = c;


	output(a.toString());
	output("");

	_stack.push_back(_factory.createOperand(Int8, "0"));
	_stack.push_back(_factory.createOperand(Int8, "1"));
	_stack.push_back(_factory.createOperand(Int8, "2"));
	_stack.push_back(c + b);

	output(_stack[0]->toString());
	output(_stack[1]->toString());
	output(_stack[2]->toString());
	output(_stack[3]->toString());

	IOperand  const * z1 = _stack.back();
	std::string sample = z1->toString();
	_stack.pop_back();
	_stack.pop_back();

	output(_stack.back()->toString());
}
