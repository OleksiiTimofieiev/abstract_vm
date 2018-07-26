#include "CPU.hpp"

int		main ( int argc, char ** argv )
{
	CPU _cpu;

	_cpu.execute_inner_logic( argc, argv[1] );
	
	return (0);
}
