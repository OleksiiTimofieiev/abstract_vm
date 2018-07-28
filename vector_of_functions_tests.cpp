#include <iostream>
#include <vector>
#include <functional>

// for the syntax simplification;
typedef std::function<void(int, int)> function_object;

// enum creation;
enum function
{
	int8 = 0,
	type_float,
	type_double,
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

void	create_double(int var, int value)
{
	std::cout << var * (value + 1) << std::endl;
}

int		main ( void )
{
	std::vector<function_object> vFunc;

	vFunc.push_back(create_int);
	vFunc.push_back(create_float);
	vFunc.push_back(create_double);

	vFunc[int8](3,3);
	vFunc[type_double](3, 3);
	vFunc[type_float](3, 3);
}
