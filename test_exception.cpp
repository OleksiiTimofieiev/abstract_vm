// #include <exception>
// #include <iostream>

// class Exception : public std::exception
// {
//   public:
// 	explicit Exception(const char *message) : msg_(message)
// 	{
// 	}
// 	explicit Exception(const std::string &message) : msg_(message)
// 	{
// 	}
// 	/** Destructor.
//      * Virtual to allow for subclassing.
//      */
// 	virtual ~Exception() throw() {}

// 	/** Returns a pointer to the (constant) error description.
//      *  @return A pointer to a const char*. The underlying memory
//      *          is in posession of the Exception object. Callers must
//      *          not attempt to free the memory.
//      */
// 	virtual const char *what() const throw()
// 	{
// 		return msg_.c_str();
// 	}

//   protected:
// 	std::string msg_;
// };

// int main()
// {
// 	try
// 	{
// 		throw Exception("Something went wrong...\n");
// 	}
// 	catch (Exception & ex)
// 	{
// 		std::cout << ex.what() << std::endl;
// 	}
// }

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

void f( int line)
{
	throw_line("\033[1;31mlexer error type 1 -> not valid command !\033[0m", line);
}

int main()
{


	int i = 0;






	while (i < 5)
	{
		try
		{
			f(42);
		}
		catch (const std::runtime_error &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		i++;
	}






	std::string	msg1 = "1";
	std::string msg2 = "2";

	std::string res = msg1 + msg2;

	std::cout << res;

	return (0);
}
