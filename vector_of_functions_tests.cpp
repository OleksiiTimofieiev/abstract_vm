#include <iostream>
#include <vector>
#include <functional>


// enum creation;
enum function
{
	type_int = 0,
	type_float,
} year;

// functions for testing;
void	create_int( int var, int value )
{
	std::cout << var + value << std::endl;
}

void	create_float( int var, int value )
{
	std::cout << var * value << std::endl;
}


int		main ( void )
{

	std::vector<std::function<void(int, int)>> list_of_functions;

	list_of_functions.emplace_back(create_int);
	list_of_functions.emplace_back(create_float);

	list_of_functions[type_int](3,3);
	list_of_functions[type_float](3, 3);
}
