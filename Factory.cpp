#include "Factory.hpp"

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
		return (new eOperand<int8_t>(static_cast<int8_t>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << x.what() << std::endl;
		return (0);
	}
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	try
	{
		int64_t num = std::stoll(value);
		return (new eOperand<int16_t>(static_cast<int16_t>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << x.what() << std::endl;
		return (0);
	}

}
IOperand const *Factory::createInt32(std::string const &value) const
{
	try
	{
		int64_t num = std::stoll(value);
		return (new eOperand<int32_t>(static_cast<int32_t>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << x.what() << std::endl;
		return (0);
	}
};
IOperand const *Factory::createFloat(std::string const &value) const
{
	try
	{
		long double num = std::stold(value);

		return (new eOperand<float>(static_cast<float>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << x.what() << std::endl;
		return (0);
	}
}
IOperand const *Factory::createDouble(std::string const &value) const
{
	try
	{
		long double num = std::stold(value);

		return (new eOperand<double>(static_cast<double>(num)));
	}
	catch (const std::exception & x)
	{
		std::cout << x.what() << std::endl;
		return (0);
	}
}
