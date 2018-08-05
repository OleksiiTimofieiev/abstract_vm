#include "../includes/CPU.hpp"

int		main2 ( int argc, char ** argv )
{
	CPU _cpu;

	_cpu._execute_inner_logic( argc, argv[1] );

	return (0);
}

int		main( int argc, char ** argv )
{
	main2(argc, argv);
	system("leaks -q avm");
	return (0);
}
