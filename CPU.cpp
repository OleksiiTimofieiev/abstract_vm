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
	std::vector<std::vector<std::string> >::iterator row_command_list;
	std::vector<std::string>::iterator col_command_list;

	bool	exit_command_is_pesent_in_command_list = false;

	for (row_command_list = _command_list.begin(); row_command_list != _command_list.end(); row_command_list++)
	{
		col_command_list = row_command_list->begin();

		if (*col_command_list == "exit")
		{
			exit_command_is_pesent_in_command_list = true;
			_exit( );
		}
	}

	if (!exit_command_is_pesent_in_command_list)
	{
		output(RED);
		output("No exit command available");
		output(COLOR_RESET);
	}
		


		

	// function with default params for the array of the functions;
	// enum for the functions

	// eOperand<int8_t> a("65");
	// eOperand<int16_t> b("2");
	// eOperand<int32_t> c("3");
	// eOperand<float> d("4");
	// eOperand<double> e("5");

	// a = c;

	// output(a.toString());
	// output("");

	// _stack.push_back(_factory.createOperand(Int8, "0"));
	// _stack.push_back(_factory.createOperand(Int8, "1"));
	// _stack.push_back(_factory.createOperand(Int32, "65"));
	// _stack.push_back(c + b);

	// output(_stack[0]->toString());
	// output(_stack[1]->toString());
	// output(_stack[2]->toString());
	// output(_stack[3]->toString()); 

	// output("");

	// IOperand  const * z1 = _stack.back();
	// std::string sample = z1->toString();
	// _stack.pop_back();
	// _stack.pop_back();

	// output(_stack.back()->toString());
	// output(_stack.back()->getType());

}
bool	CPU::print( void )
{

	fprintf(stdout, "[%d]: %c;\n", stoi(_stack.back()->toString()), stoi(_stack.back()->toString()));
	return(true);
}

void	CPU::_exit( void )
{
	exit(0);
}

