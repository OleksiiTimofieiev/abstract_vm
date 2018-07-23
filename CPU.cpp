#include "CPU.hpp"

CPU::CPU () {};
CPU::~CPU()	{};
// TODO: copy constructor;
// TODO: init constructor;

/* ********************************************************************************************************************************************************************************** */

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

	// TODO: add the data to the linked list;
	while( reading )
	{
		printf( "%ld. ", line_number++ );

		if ( std::getline(std::cin, input) && !input.empty() )
			std::cout << input << std::endl;
		else
			reading = false;
	}
}

void	CPU::read( const int quantity_of_arguments )
{
	if ( detect_input_stream( quantity_of_arguments ) )
		std::cout << "bla" << std::endl;
		//TODO:: eof for checking;
	else
		read_from_the_standart_input();
}

void	CPU::detect_leaks( void ) { system("leaks -q avm"); }
