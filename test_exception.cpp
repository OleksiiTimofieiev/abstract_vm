#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception
{
	const char *what() const throw()
	{
		std::string adf = "asd";
		return adf.c_str();
	}
};

int main()
{
	try
	{
		throw MyException();
	}
	catch (MyException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		//Other errors
	}
}
