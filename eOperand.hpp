#ifndef EOPERAND_HPP
#define EOPERAND_HPP

#include "IOperand.hpp"
#include "Factory.hpp"

//TODO:copl form
//TODO:exceptions

template <typename T>
class eOperand : public IOperand
{
	public:
		eOperand(const std::string & str);

		eOperand( void );
		~eOperand( void );
		IOperand const &operator=(eOperand const &rhs);
		eOperand(eOperand const &src);

		int 			getPrecision( void ) const;
		eOperandType 	getType( void ) const;
		IOperand const *operator+(IOperand const &rhs) const;
		// IOperand const *operator-(IOperand const &rhs) const;
		// IOperand const *operator*(IOperand const &rhs) const;
		// IOperand const *operator/(IOperand const &rhs) const;
		// IOperand const *operator%(IOperand const &rhs) const;
		std::string const &toString(void) const;
		
	private:
		std::string		_value;
		T				_value_after_conversion;
};

#endif
