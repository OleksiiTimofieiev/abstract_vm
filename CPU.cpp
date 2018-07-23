#include "CPU.hpp"

CPU::CPU () {};
CPU::~CPU()	{};

bool	CPU::detect_input_stream( int quantity_of_arguments )
{
	if ( quantity_of_arguments == 2)
		return ( true );
	return ( false );
}

void	CPU::read_from_the_standart_input( void )
{
	std::string		input;

	// TODO: add the data to the linked list;
	while(std::getline(std::cin, input))
	{
		std::cout << input << std::endl;
	}
}

void CPU::read( int quantity_of_arguments )
{
	if (detect_input_stream( quantity_of_arguments ))
		std::cout << "bla" << std::endl;
	else
		read_from_the_standart_input();
}
