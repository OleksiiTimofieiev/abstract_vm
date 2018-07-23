#include "CPU.hpp"

int		main ( int argc, char ** argv )
{
	// TODO: skip the not valid line with continue;

	// TODO: how to show all exception cases in the end of the execution;

	// TODO: create exeption class; how to pass it by reference; redo the methods of the class;

	CPU _cpu;

	_cpu.execute_inner_logic( argc, argv[1]);

	return (0);
}
