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
		// char = 1;
		// short = 2;
		// int = 4;
		// float = 4;
		// double = 8;
		if (sizeof(_value) == 8)
			_value = stoi(str);
	}

	void data_type_size()
	{
		std::cout << sizeof(_value) << _value << std::endl;
	}

	~eOperand(void){};
private:
	T		_value;
};

#endif
