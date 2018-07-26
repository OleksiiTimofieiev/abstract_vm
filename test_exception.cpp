#include <exception>
#include <iostream>

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

#define throw_line(arg) throw my_exception(arg, __FILE__, __LINE__ - 1);

void f()
{
	throw_line("\033[1;31mlexer error type 1 -> not valid command !\033[0m");
}

int main()
{
	int i = 0;

	while (i < 5)
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
