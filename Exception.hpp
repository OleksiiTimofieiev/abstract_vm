#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

class my_exception : public std::runtime_error
{
	std::string _msg;
	std::string _result;
	int _line;

  public:
	my_exception(const std::string &arg, int line) : std::runtime_error(arg)
	{
		_msg = arg;
		_line = line;

		_msg = _msg + std::to_string(_line);
	}

	~my_exception() throw() {}

	const char *what() const throw()
	{
		return _msg.c_str();
	}
};

#define throw_line(arg, line) throw my_exception(arg, line);

void f(int line)
{
	throw_line("\033[1;31mlexer error type 1 -> not valid command !\033[0m", line);
}

#endif
