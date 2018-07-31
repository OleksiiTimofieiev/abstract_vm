#ifndef EOPERAND_HPP
#define EOPERAND_HPP

#include "IOperand.hpp"

class	eOperand : public IOperand
{
public:
	int getPrecision(void) const = 0;	 // add it to the constructor with private variable;
	eOperandType getType(void) const = 0; // different	func;
	IOperand const *operator+(IOperand const &rhs) const = 0;
	IOperand const *operator-(IOperand const &rhs) const = 0;
	IOperand const *operator*(IOperand const &rhs) const = 0;
	IOperand const *operator/(IOperand const &rhs) const = 0;
	IOperand const *operator%(IOperand const &rhs) const = 0;

	std::string const &toString(void) const = 0; // int to string

	~eOperand(void){};
};

#endif
