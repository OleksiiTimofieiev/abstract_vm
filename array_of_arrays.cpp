#include <iostream>
#include <array>
#include <vector>






















int		main( void )
{
	int				size = 4;

	std::string		command = "push";
	std::string 	type = "int8";
	std::string 	value = "42";

	std::vector<std::vector<std::string> > arr(size);

	arr[0].push_back(command);
	arr[0].push_back(type);
	arr[0].push_back(value);

	// arr[0][0] = command;
	// arr[0][1] = type;
	// arr[0][2] = value;

	// arr[1][0] = command;
	// arr[1][1] = type;
	// arr[1][2] = value;

	// arr[2][0] = command;
	// arr[2][1] = type;
	// arr[2][2] = value;

	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[0][i] << std::endl;
	}

	system("leaks -q a.out");

	return (0);
}
