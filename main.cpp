#include "Parser.hpp"

int		main ( int argc, char ** argv )
{
	// TODO: skip the not valid line with continue;

	// TODO: how to show all exception cases in the end of the execution;

	Parser Parser;

	Parser.read( argc, argv[1] );
	Parser.print_list();
	Parser.detect_leaks();

	return (0);
}
