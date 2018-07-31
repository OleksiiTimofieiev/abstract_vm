#ifndef EOPERAND_HPP
#define EOPERAND_HPP

#include "IOperand.hpp"

// private / protected variables;

template<typename T>

class	eOperand : public IOperand
{
public:
	// int 			getPrecision(void) const;
	// eOperandType 	getType(void) const; 
	// IOperand const *operator+(IOperand const &rhs) const;
	// IOperand const *operator-(IOperand const &rhs) const;
	// IOperand const *operator*(IOperand const &rhs) const;
	// IOperand const *operator/(IOperand const &rhs) const;
	// IOperand const *operator%(IOperand const &rhs) const;

	// std::string const &toString(void) const; // int to string
	eOperand(){};

	eOperand(const std::string & str)
	{
		// char = 'c';
		// short = 's';
		// int = 'i';
		// float = 'f';
		// double = 'd';
		std::string type;

		type = typeid(T).name();

		std::cout << type;

		if (type == "i")
			_value_after_conversion = stoi(str);
	}

	void data_type_size()
	{
		std::cout << sizeof(_value_after_conversion) << _value_after_conversion << std::endl;
	}

	~eOperand(void){};
private:
	std::string		_value;
	T				_value_after_conversion;
};

#endif
