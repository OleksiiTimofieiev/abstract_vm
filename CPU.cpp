#include "CPU.hpp"
#include "Factory.hpp"

// • An assert instruction is not true

// bonus:
// min
// max
// increment
// decrement
// sort
// usage
// ncurses avm

// make cool makefile;

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

CPU::CPU( CPU const &src )
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

		if 		(*col_command_list == "push")
			_push(*std::next(col_command_list, 1) , *std::next(col_command_list, 2));
		else if (*col_command_list == "assert")
			_assert(*std::next(col_command_list, 1) , *std::next(col_command_list, 2), line);
		else if (*col_command_list == "pop")
			_pop(line);
		else if (*col_command_list == "dump")
			_dump(line);
		else if (*col_command_list == "print")
			_print(line);
		else if (*col_command_list == "add")
			_add(line);
		else if (*col_command_list == "sub")
			_sub(line);
		else if (*col_command_list == "mul")
			_mul(line);
		else if (*col_command_list == "div")
			_div(line);
		else if (*col_command_list == "mod")
			_mod(line);
		else if (*col_command_list == "exit")
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

void	CPU::_pop( int line )
{
	try
	{
		if (_stack.empty())
			throw_line("\033[1;31mTry to pop empty stack on line # -> \033[0m", line);
		_stack.pop_back();
	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_dump( int line )
{
	try
	{
		if (_stack.empty())
			throw_line("\033[1;31mTry to dump empty stack on line # -> \033[0m", line);

			for ( auto i = _stack.end();i != _stack.begin(); ) 
			{
				--i;
				IOperand const* z = *i;
				OUTPUT(z->toString());
			}
	}
	catch ( const std::runtime_error &ex )
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_add( int line )
{
	try
	{
		if ( _stack.size() < 2 )
			throw_line("\033[1;31mTry to add on stack < 2 elements on line # -> \033[0m", line);
		ssize_t	size = _stack.size();
		ssize_t	last = size - 1;
		ssize_t	prev_last = last - 1;

		IOperand const * a = _stack.at(prev_last);
		IOperand const * b = _stack.at(last);

		_stack.push_back(*a + *b);

		_stack.erase(_stack.begin() + (_stack.size() - 2));
		_stack.erase(_stack.begin() + (_stack.size() - 2));
	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_sub( int line )
{
	try
	{
		if ( _stack.size() < 2 )
			throw_line("\033[1;31mTry to sub on stack < 2 elements on line # -> \033[0m", line);
		ssize_t	size = _stack.size();
		ssize_t	last = size - 1;
		ssize_t	prev_last = last - 1;

		IOperand const * a = _stack.at(prev_last);
		IOperand const * b = _stack.at(last);
		
		_stack.push_back(*a - *b);

		_stack.erase(_stack.begin() + (_stack.size() - 2));
		_stack.erase(_stack.begin() + (_stack.size() - 2));
	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_mul( int line )
{
	try
	{
		if ( _stack.size() < 2 )
			throw_line("\033[1;31mTry to mul on stack < 2 elements on line # -> \033[0m", line);
		ssize_t	size = _stack.size();
		ssize_t	last = size - 1;
		ssize_t	prev_last = last - 1;

		IOperand const * a = _stack.at(prev_last);
		IOperand const * b = _stack.at(last);
		
		_stack.push_back(*a * *b);

		_stack.erase(_stack.begin() + (_stack.size() - 2));
		_stack.erase(_stack.begin() + (_stack.size() - 2));
	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_div( int line )
{
	try
	{
		if ( _stack.size() < 2 )
			throw_line("\033[1;31mTry to div on stack < 2 elements on line # -> \033[0m", line);
		ssize_t	size = _stack.size();
		ssize_t	last = size - 1;
		ssize_t	prev_last = last - 1;

		IOperand const * a = _stack.at(prev_last);
		IOperand const * b = _stack.at(last);
	
		if ( a->toString() == "0" || b->toString() == "0" )
			throw_line("\033[1;31mDiv command with 0 operator on line # -> \033[0m", line);

		_stack.push_back(*a / *b);

		_stack.erase(_stack.begin() + (_stack.size() - 2));
		_stack.erase(_stack.begin() + (_stack.size() - 2));
	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_mod( int line )
{
	try
	{
		if ( _stack.size() < 2 )
			throw_line("\033[1;31mTry to mod on stack < 2 elements on line # -> \033[0m", line);
		ssize_t	size = _stack.size();
		ssize_t	last = size - 1;
		ssize_t	prev_last = last - 1;

		IOperand const * a = _stack.at(prev_last);
		IOperand const * b = _stack.at(last);
	
		if ( a->toString() == "0" || b->toString() == "0" )
			throw_line("\033[1;31mDiv command with 0 operator on line # -> \033[0m", line);

		_stack.push_back(*a % *b);

		_stack.erase(_stack.begin() + (_stack.size() - 2));
		_stack.erase(_stack.begin() + (_stack.size() - 2));
	}
	catch (const std::runtime_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_print( int line )
{
	try
	{
		auto i = _stack.back()->getType();
		
		if ( _stack.empty() )
			throw_line("\033[1;31mTry to print on empty stack on line # -> \033[0m", line);

		if ( !i )
			fprintf(stdout, "[%d]: %c;\n", stoi(_stack.back()->toString()), stoi(_stack.back()->toString()));
		else
			throw_line("\033[1;31mPrint error on line # -> \033[0m", line);
	}
	catch ( const std::runtime_error &ex )
	{
		std::cout << ex.what() << std::endl;
	}
}

void	CPU::_assert( std::string Type, std::string value, int line )
{
	
	
	eOperandType selector;

	if (Type == "int8") {selector = Int8;}
	else if (Type == "int16") {selector = Int16;}
	else if (Type == "int32") {selector = Int32;}
	else if (Type == "float") {selector = Float;}
	else if (Type == "double") {selector = Double;}
	else
		selector = default_value;
	try
	{
		if ( _stack.empty() )
			throw_line("\033[1;31mTry to assert with empty stack on line # -> \033[0m", line);

		IOperand const * b = _stack.back();

		IOperand const * a = _factory.createOperand(selector, value);

		if ( a->toString() == "0" )
		{
			delete	(a);
			throw_line("\033[1;31mTry to assert with zero value on line # -> \033[0m", line);
		}
		
		if (*a == *b)
		{
			OUTPUT_MAGENTA("Equal values !!!");
		}
		else 
			OUTPUT_RED("Nope. Not equal values. Too bad.");
		delete	(a);
	}
	catch ( const std::runtime_error &x )
	{
		std::cout << x.what() << std::endl;
	}





}

void	CPU::_exit( void )
{
	exit(0);
}
