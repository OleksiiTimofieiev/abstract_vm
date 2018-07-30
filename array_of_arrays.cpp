#include <iostream>
#include <array>






















int		main( void )
{
	std::string		command = "push";
	std::string 	type = "int8";
	std::string 	value = "42";

	std::array<std::array<std::string,3>, 3> arr;

	arr[0][0] = command;
	arr[0][1] = type;
	arr[0][2] = value;

	arr[1][0] = command;
	arr[1][1] = type;
	arr[1][2] = value;

	arr[2][0] = command;
	arr[2][1] = type;
	arr[2][2] = value;

	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[0][i] << std::endl;
	}

	return (0);
}
