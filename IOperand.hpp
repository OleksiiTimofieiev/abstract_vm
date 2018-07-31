#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>

enum eOperandType {Int8, Int16, Int32, Float, Double};

class IOperand
{ 
private:
public:
  virtual int				getPrecision(void) const = 0;				// add it to the constructor with private variable;
  virtual eOperandType 		getType(void) const = 0;					// different	func;
  virtual IOperand const *	operator+(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator-(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator*(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator/(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator%(IOperand const &rhs) const = 0;

  virtual std::string const &toString(void) const = 0;					// int to string 

  virtual ~IOperand(void){};
};

#endif
