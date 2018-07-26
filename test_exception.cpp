#include <iostream>
#include <stdexcept>

class GolfError : public std::runtime_error
{
  public:
	GolfError(const char *what) : runtime_error(what) {}
};

int main()
{
	int x = 8;

	try
	{
		x = 9;
		if (x == 9)
			throw GolfError("asdfadf");
	}
	catch (GolfError & e)
	{
		std::cout << e.what();
	}
}
