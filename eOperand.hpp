#ifndef EOPERAND_HPP
#define EOPERAND_HPP

#include "IOperand.hpp"

// private / protected variables;
//TODO:copl form
//TODO:exceptions

template <typename T>

class eOperand : public IOperand
{
	public:
		int 			getPrecision( void ) const
		{
			std::string type = typeid(T).name();

			if (type == "c")
				return (Int8);
			else if (type == "s")
				return (Int16);
			else if (type == "i")
				return (Int32);
			else if (type == "f")
				return (Float);
			else if (type == "d")
				return (Double);

			return (default_value);
		}
		eOperandType 	getType( void ) const
		{
			std::string type = typeid(T).name();

			if (type == "c")
				return (Int8);
			else if (type == "s")
				return (Int16);
			else if (type == "i")
				return (Int32);
			else if (type == "f")
				return (Float);
			else if (type == "d")
				return (Double);

			return (default_value);
		}

		// IOperand const *operator+(IOperand const &rhs) const;
		// IOperand const *operator-(IOperand const &rhs) const;
		// IOperand const *operator*(IOperand const &rhs) const;
		// IOperand const *operator/(IOperand const &rhs) const;
		// IOperand const *operator%(IOperand const &rhs) const;

		std::string const &toString(void) const
		{
			return (_value);
		}
		eOperand(const std::string & str) : _value(str)
		{
			std::string type;

			type = typeid(T).name();

			if (type == "i")
				_value_after_conversion = stoi(str);
		}
		eOperand( void ) {};
		~eOperand( void ) {};
		
	private:
		std::string		_value;
		T				_value_after_conversion;
};

#endif
