#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

#define throw_line(arg, line) throw Exception(arg, line);

class Exception : public std::runtime_error
{
	std::string _msg;
	std::string _result;
	int _line;

  public:
	Exception(const std::string &arg, int line);

	~Exception() throw();

	const char *what() const throw();
};




#endif
