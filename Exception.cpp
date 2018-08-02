#include "Exception.hpp"

Exception::Exception() : std::runtime_error("no error") {}
Exception::~Exception() throw() {}
Exception &Exception::operator=(Exception const &rhs)
{
	if (this != &rhs)
		_msg = rhs._msg;
		_result = rhs._result;
		_line = rhs._line;	
	return *this;
}

Exception::Exception (Exception const &src) : std::runtime_error("no error")
{
	*this = src;
}


Exception::Exception(const std::string &arg, int line) : std::runtime_error(arg)
{
	_msg = arg;
	_line = line;
	
	_msg = _msg + std::to_string(_line);
}


const char *Exception::what() const throw()
{
	return _msg.c_str();
}
