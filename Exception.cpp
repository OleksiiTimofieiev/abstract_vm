#include "Exception.hpp"

Exception::Exception() : std::runtime_error("no error") {}


Exception::Exception(const std::string &arg, int line) : std::runtime_error(arg)
{
	_msg = arg;
	_line = line;
	
	_msg = _msg + std::to_string(_line);
}

Exception::~Exception() throw() {}

const char *Exception::what() const throw()
{
	return _msg.c_str();
}
