#include "CPU.hpp"

int		main2 ( int argc, char ** argv )
{
	// try
	// {
		CPU _cpu;

		_cpu._execute_inner_logic( argc, argv[1] );
	// }
	// catch(const std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	return (0);
}

int		main( int argc, char ** argv )
{
	main2(argc, argv);
	system("leaks -q avm");
	return (0);
}
