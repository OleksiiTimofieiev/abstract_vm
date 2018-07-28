#include <iostream>
#include <vector>
#include <functional>

// for the syntax simplification;
typedef std::function<void(int, int)> function_object;

// enum creation;
enum function {
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
	std::cout << var * (value * 10) << std::endl;
}

int		main ( void )
{
	std::vector<int> vc;

	std::vector<function_object> vFunc;

	vFunc.push_back(create_int);
	vFunc.push_back(create_float);

	vFunc[type_int](3,3);
	vFunc[type_float](3, 3);
}
