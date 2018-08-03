#include "CPU.hpp"
#include "Factory.hpp"

// • Overflow on a value
// • Underflow on a value
// • Instruction pop on an empty stack
// • Division/modulo by 0
// • An assert instruction is not true
// • The stack is composed of strictly less that two values when an arithmetic instruction is executed.

// -DBL/float_MAX
// long double;
// stdint
// float
// 1. static cast for the string value, 2. do smth - check Pasha method;
// cast to the bigger value, even assert;
// make cool makefile;
// IOperand const* z = _stack.back();
// std::cout << z->toString() << std::endl;
// fprintf(stdout, "[%d]: %c;\n", stoi(_stack.back()->toString()), stoi(_stack.back()->toString()));
//TODO:		check all command for the seg abort with empty stack; exception throw;
//TODO:		check copl form in the end of the project;
//TODO:		test1 comments;

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
	OUTPUT_CYAN("And here we go ... ;)");
	_commands_execution_routine	();
}

void	CPU::_commands_execution_routine()
{
	std::vector<std::vector<std::string> >::iterator row_command_list;
	std::vector<std::string>::iterator col_command_list;

	bool exit_command_is_pesent_in_command_list = false;
	int	line = 0;;

	for ( row_command_list = _command_list.begin(); row_command_list != _command_list.end(); row_command_list++ )
	{
		col_command_list = row_command_list->begin();

		++line;

		if (*col_command_list == "push")
			_push(*std::next(col_command_list, 1) , *std::next(col_command_list, 2));
		else if (*col_command_list == "pop")
			_pop();
		else if (*col_command_list == "dump")
			_dump();
		else if (*col_command_list == "print")
			_print(line);
		else if (*col_command_list == "exit") // move forward iterator to have its value;
		{
			exit_command_is_pesent_in_command_list = true;
			_exit();
		}
	}

	if ( !exit_command_is_pesent_in_command_list )
		OUTPUT_RED( "No exit command available." );
}

void	CPU::_push( std::string Type, std::string value )
{
	eOperandType selector;

	if (Type == "int8") 
		selector = Int8;
	else if (Type == "int16")
		selector = Int16;
	else if (Type == "int32") 
		selector = Int32;
	else if (Type == "float") 
		selector = Float;
	else if (Type == "double")
		selector = Double;
	else
		selector = default_value;

	_stack.push_back(_factory.createOperand(selector, value));
}

void	CPU::_pop( )
{
	_stack.pop_back();
}

void	CPU::_dump()
{
	for (auto i = _stack.end();i != _stack.begin(); ) 
	{
  		--i;
		IOperand const* z = *i;
		OUTPUT(z->toString());
	}
}

void	CPU::_print( int line )
{
	auto i = _stack.back()->getType();

	try
	{
		if (!i)
			fprintf(stdout, "[%d]: %c;\n", stoi(_stack.back()->toString()), stoi(_stack.back()->toString()));
		else
			throw_line("\033[1;31mPrint error on line # -> \033[0m", line);

	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_exit( void )
{
	exit(0);
}
