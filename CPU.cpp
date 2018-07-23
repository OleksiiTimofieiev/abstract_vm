#include "CPU.hpp"

/* construction ************************************************************************************************************************** */

CPU::CPU () {}
CPU::~CPU()	{}

// TODO: copy constructor;
// TODO: init constructor;

/* main ********************************************************************************************************************************* */

bool	CPU::detect_input_stream( const int quantity_of_arguments ) const
{
	if ( quantity_of_arguments == 2)
		return ( true );
	return ( false );
}

void	CPU::read_from_the_standart_input( void )
{
	ssize_t			line_number = 1;
	std::string		input;
	int				reading = true;

	while( reading )
	{
		printf( "%ld. ", line_number++ );

		if ( std::getline(std::cin, input) )
		{
			if ( !input.empty() )
				_filtered_input.push_back(input);
		}
		else
			reading = false;
	}
}

void	CPU::read_from_the_ifstream( char * argument )
{
	// ssize_t line_number = 1;
	std::string	path = 	argument;
	std::ifstream		fin;
	std::string			input = "";

	fin.open(path);

	if ( !fin.is_open() )
	{
		// TODO: hadle with exeption;
		std::cout << "error";
	}
	else
	{
		while( !(fin.eof()) )
		{
			getline( fin, input);

			if (!input.empty())
				_filtered_input.push_back(input);
		}
	}
	fin.close();
}

void CPU::read( const int quantity_of_arguments, char * argument )
{
	if ( detect_input_stream( quantity_of_arguments ) )
		read_from_the_ifstream( argument );
	else
		read_from_the_standart_input();
}

/* infrastructure ******************************************************************************************************************* */

void	CPU::print_list( void )
{
	std::cout << std::endl;
	std::cout << std::endl;

	if ( !_filtered_input.empty() )
	{
		for ( auto i = _filtered_input.cbegin(); i != _filtered_input.cend(); ++i )
			std::cout << *i << std::endl;
	}

	std::cout << std::endl;
}

void	CPU::detect_leaks( void ) { system("leaks -q avm"); }
