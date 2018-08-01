#ifndef FACTORY_HPP
#define	FACTORY_HPP

#include "eOperand.hpp"
#include <functional>
#include <vector>

class	Factory
{
	public:
		IOperand const *createOperand(eOperandType type, std::string const &value) const
		{
			return ((*this.*_vFunc.at(type))(value));
		}
	Factory( void )
	{
		_vFunc.push_back(&Factory::createInt8);
		_vFunc.push_back(&Factory::createInt16);
		_vFunc.push_back(&Factory::createInt32);
		_vFunc.push_back(&Factory::createFloat);
		_vFunc.push_back(&Factory::createDouble);
	}
	~Factory( void) {}
	Factory &operator=(Factory const &rhs)
	{
		if (this != &rhs)
			this->_vFunc = rhs._vFunc;
		return *this;
	}
	Factory(Factory const &src)
	{
		*this = src;
	}
  	private:
		IOperand const *createInt8(std::string const &value) const
		{
		  return (new eOperand<char>(value));
		}
	  	IOperand const *createInt16(std::string const &value) const
		{
			return (new eOperand<short>(value));
		}
	  	IOperand const *createInt32(std::string const &value) const
		{
			return (new eOperand<int>(value));
		};
		IOperand const *createFloat(std::string const &value) const
		{
			return (new eOperand<float>(value));
		}
		IOperand const *createDouble(std::string const &value) const
		{
			return (new eOperand<double>(value));
		}
		std::vector<IOperand const *(Factory::*)(std::string const &value) const> _vFunc;
};

#endif
