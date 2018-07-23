#include "CPU.hpp"

int		main ( int argc, char ** argv )
{
	// TODO: skip the not valid line with continue;

	// TODO: how to show all exception cases in the end of the execution;

	CPU cpu;

	cpu.read( argc );



	cpu.print_list();



	(void)argv;

	cpu.detect_leaks();

	return (0);
}
