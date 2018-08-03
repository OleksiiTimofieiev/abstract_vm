#include <iostream>
#include <regex>

int		main(void)
{
	std::smatch		result;
	const 			std::regex	taras("push\\sint16\\(([-]?\\d{1,5})\\)\\s*(;.*)?");

	std::string str = "push int16(-99999)";
	
	if ((std::regex_match( str, result, taras)))
	{
		std::cout << "true" << std::endl;
	}

	return (0);
}
