#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class my_exception : public std::runtime_error
{
	std::string msg;

  	public:
	my_exception(const std::string &arg, const char *file, int line) : std::runtime_error(arg)
	{
		std::ostringstream o;
		o << file << ":" << line << ": " << arg;
		msg = o.str();
	}
	~my_exception() throw() {}
	const char *what() const throw()
	{
		return msg.c_str();
	}
};
#define throw_line(arg) throw my_exception(arg, __FILE__, __LINE__);

void f()
{
	throw_line("some error!");
}

int main()
{
	int i = 0;

	while ( i < 5)
	{
		try
		{
			f();
		}
		catch (const std::runtime_error &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		i++;
	}
}
