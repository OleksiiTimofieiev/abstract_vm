#include <iostream>

enum eOperandType
{
	Int8 = 0,
	Int16,
	Int32,
	Float,
	Double,
};

class IOperand
{ 
private:
public:
  virtual int				getPrecision(void) const = 0;
  virtual eOperandType 		getType(void) const = 0;
  virtual IOperand const *	operator+(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator-(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator*(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator/(IOperand const &rhs) const = 0;
  virtual IOperand const *	operator%(IOperand const &rhs) const = 0;

  virtual std::string const &toString(void) const = 0;

  virtual ~IOperand(void){};
};
