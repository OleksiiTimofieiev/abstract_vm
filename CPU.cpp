#include "CPU.hpp"
#include "Factory.hpp"

CPU::CPU () {}

CPU::~CPU() 
{
	for ( auto i = _stack.begin(); i != _stack.end(); ++i )
		delete *i;
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
	// _parser.print_list();

	std::vector<std::vector<std::string> >::iterator row_command_list;
	std::vector<std::string>::iterator col_command_list;

	bool exit_command_is_pesent_in_command_list = false;

	for ( row_command_list = _command_list.begin(); row_command_list != _command_list.end(); row_command_list++ )
	{
		col_command_list = row_command_list->begin();

		if (*col_command_list == "exit")
		{
			exit_command_is_pesent_in_command_list = true;
			_exit( );
		}
	}

	if ( !exit_command_is_pesent_in_command_list )
		OUTPUT_RED( "No exit command available." );
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
