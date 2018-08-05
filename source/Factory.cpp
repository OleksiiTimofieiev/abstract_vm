#include "../includes/Factory.hpp"
#include "../includes/Exception.hpp"
#include <float.h>

Factory::Factory( void )
{
	_vFunc.push_back(&Factory::createInt8);
	_vFunc.push_back(&Factory::createInt16);
	_vFunc.push_back(&Factory::createInt32);
	_vFunc.push_back(&Factory::createFloat);
	_vFunc.push_back(&Factory::createDouble);
}

Factory::~Factory(void) {}

Factory &Factory::operator=(Factory const &rhs)
{
	if (this != &rhs)
		this->_vFunc = rhs._vFunc;
	return *this;
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	return ((*this.*_vFunc.at(type))(value));
}
Factory::Factory(Factory const &src)
{
	*this = src;
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	try
	{
		int64_t num = std::stoll(value);

		if ( num > std::numeric_limits<int8_t>::max())
			throw_line("Overflow happend, value to be factorized -> ", 0);
		if ( num < std::numeric_limits<int8_t>::min())
			throw_line("Underflow happend, value to be factorized -> ", 0);

		return (new eOperand<int8_t>(static_cast<int8_t>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << "\033[1;31m" << x.what() << "\x1B[0m" << std::endl;
		return (NULL);
	}
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	try
	{
		int64_t num = std::stoll(value);

		if ( num > std::numeric_limits<int16_t>::max())
			throw_line("Overflow happend, value to be factorized -> ", 0);
		if ( num < std::numeric_limits<int16_t>::min())
			throw_line("Underflow happend, value to be factorized -> ", 0);

		return (new eOperand<int16_t>(static_cast<int16_t>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << "\033[1;31m" << x.what() << "\x1B[0m" << std::endl;
		return (0);
	}

}
IOperand const *Factory::createInt32(std::string const &value) const
{
	try
	{
		int64_t num = std::stoll(value);

		if ( num < INT32_MIN)
			throw_line("Underflow happend, value to be factorized -> ", 0);
		if ( num > INT32_MAX)
			throw_line("Overflow happend, value to be factorized -> ", 0);

		return (new eOperand<int32_t>(static_cast<int32_t>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << "\033[1;31m" << x.what() << "\x1B[0m" << std::endl;
		return (0);
	}
};
IOperand const *Factory::createFloat(std::string const &value) const
{
	try
	{
		long double num = std::stold(value);

		if ( num < -FLT_MAX)
			throw_line("Underflow happend, value to be factorized -> ", 0);
		if ( num > FLT_MAX)
			throw_line("Overflow happend, value to be factorized -> ", 0);

		return (new eOperand<float>(static_cast<float>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << "\033[1;31m" << x.what() << "\x1B[0m" << std::endl;
		return (0);
	}
}
IOperand const *Factory::createDouble(std::string const &value) const
{
	try
	{
		long double num = std::stold(value);

		if ( num < -DBL_MAX)
			throw_line("Underflow happend, value to be factorized -> ", 0);
		if ( num > DBL_MAX)
			throw_line("Overflow happend, value to be factorized -> ", 0);

		return (new eOperand<double>(static_cast<double>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << "\033[1;31m" << x.what() << "\x1B[0m" << std::endl;
		return (0);
	}
}
