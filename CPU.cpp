#include "CPU.hpp"
#include "Factory.hpp"

CPU::CPU () {}
CPU::~CPU() 
{
	for ( auto i = _stack.begin(); i != _stack.end(); ++i )
	{
		delete *i;
	}
}

CPU &CPU::operator=(CPU const &rhs)
{
	if (this != &rhs)
		_parser = rhs._parser;
		_lexer = rhs._lexer;
		_factory = rhs._factory;
		_command_list = rhs._command_list;
		_stack = rhs._stack;
		
	return *this;
}

CPU::CPU(CPU const &src)
{
	*this = src;
}

void	CPU::_execute_inner_logic(const int quantity_of_arguments, char *argument)
{
	_parser.read				( quantity_of_arguments, argument );
	_lexer.lexical_analysis		( _parser, _command_list );
	_commands_execution_routine	();
}

void	CPU::_commands_execution_routine()
{
	std::vector<std::vector<std::string> >::iterator row_command_list;
	std::vector<std::string>::iterator col_command_list;

	bool	exit_command_is_pesent_in_command_list = false;

	for 	( row_command_list = _command_list.begin(); row_command_list != _command_list.end(); row_command_list++ )
	{
			col_command_list = row_command_list->begin();

			if (*col_command_list == "exit")
			{
				exit_command_is_pesent_in_command_list = true;
				_exit( );
			}
	}

	if ( 	!exit_command_is_pesent_in_command_list )
			OUTPUT_RED( "No exit command available." );
		


		

	// function with default params for the array of the functions;
	// enum for the functions

	// eOperand<int8_t> a("65");
	// eOperand<int16_t> b("2");
	// eOperand<int32_t> c("3");
	// eOperand<float> d("4");
	// eOperand<double> e("5");

	// a = c;

	// OUTPUT(a.toString());
	// OUTPUT("");

	_stack.push_back(_factory.createOperand(Int8, "0"));
	_stack.push_back(_factory.createOperand(Int8, "1"));
	_stack.push_back(_factory.createOperand(Int32, "65"));
	// _stack.push_back(c + b);

	// OUTPUT(_stack[0]->toString());
	// OUTPUT(_stack[1]->toString());
	// OUTPUT(_stack[2]->toString());
	// OUTPUT(_stack[3]->toString()); 

	// OUTPUT("");

	// IOperand  const * z1 = _stack.back();
	// std::string sample = z1->toString();
	// _stack.pop_back();
	// _stack.pop_back();

	// OUTPUT(_stack.back()->toString());
	// OUTPUT(_stack.back()->getType());

}
bool	CPU::_print( void )
{

	fprintf(stdout, "[%d]: %c;\n", stoi(_stack.back()->toString()), stoi(_stack.back()->toString()));
	return(true);
}

void	CPU::_exit( void )
{
	exit(0);
}
