#ifndef EXCEPTION_CPP
#define	EXCEPTION_CPP

#include <exception>
#include <iostream>

class Exception : public std::exception
{
  private:
	int _line;

  public:
	const char *what()
	{
		return ("");
	}
};















#endif
