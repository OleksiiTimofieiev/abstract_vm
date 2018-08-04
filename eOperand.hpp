#ifndef EOPERAND_HPP
#define EOPERAND_HPP

#include "IOperand.hpp"
#include "Factory.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath> 

template <typename T>
class eOperand : public IOperand
{
	public:
		eOperand(T value);
		eOperand( void );
		~eOperand( void );
		IOperand const &operator=(eOperand const &rhs);
		eOperand(eOperand const &src);

		int 			getPrecision( void ) const;
		eOperandType 	getType( void ) const;
		
		IOperand const *operator+(IOperand const &rhs) const;
		IOperand const *operator-(IOperand const &rhs) const;
		IOperand const *operator*(IOperand const &rhs) const;
		IOperand const *operator/(IOperand const &rhs) const;
		IOperand const *operator%(IOperand const &rhs) const;
		bool 			operator==(IOperand const &rhs) const;
		bool 			operator>(IOperand const &rhs) const;
		std::string const &toString(void) const;
		
	private:
		T				_value;
		std::string		_str;
};

#endif
