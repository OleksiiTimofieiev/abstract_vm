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

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	return ((*this.*_vFunc.at(type))(value));
}
Factory &Factory::operator=(Factory const &rhs)
{
	if (this != &rhs)
		this->_vFunc = rhs._vFunc;
	return *this;
}
Factory::Factory(Factory const &src)
{
	*this = src;
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return (new eOperand<char>(value));
}
IOperand const *Factory::createInt16(std::string const &value) const
{
	return (new eOperand<short>(value));
}
IOperand const *Factory::createInt32(std::string const &value) const
{
	return (new eOperand<int>(value));
};
IOperand const *Factory::createFloat(std::string const &value) const
{
	return (new eOperand<float>(value));
}
IOperand const *Factory::createDouble(std::string const &value) const
{
	return (new eOperand<double>(value));
}
