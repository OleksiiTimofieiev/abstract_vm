#include <exception>
#include <iostream>

class Exception : public std::exception
{
  public:
	explicit Exception(const char *message) : msg_(message)
	{
	}
	explicit Exception(const std::string &message) : msg_(message)
	{
	}
	/** Destructor.
     * Virtual to allow for subclassing.
     */
	virtual ~Exception() throw() {}

	/** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *          is in posession of the Exception object. Callers must
     *          not attempt to free the memory.
     */
	virtual const char *what() const throw()
	{
		return msg_.c_str();
	}

  protected:
	std::string msg_;
};

int main()
{
	try
	{
		throw Exception("Something went wrong...\n");
	}
	catch (Exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
