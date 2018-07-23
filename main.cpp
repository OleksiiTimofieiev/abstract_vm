#include "CPU.hpp"

int		main ( int argc, char ** argv )
{
	// TODO: start the project;
	// TODO: skip the not valid line with continue, use linked list stl;
	// TODO: how to show all exception cases in the end of the execution;

	CPU cpu;

	cpu.read( argc );

	(void)(argv);

	// if ( cpu.detect_input_stream( argc ) )
	// {
	// 	std::cout << argv[1] << std::endl;
	// }

	cpu.detect_leaks();
	return (0);
}
