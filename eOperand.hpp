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
		eOperand(const std::string & str) : _value(str)
		{
			std::string type;

			type = typeid(T).name();

			//TODO::check input value;

			if (type == "c")
				_value_after_conversion = stoi(str);
			else if (type == "s")
				_value_after_conversion = stoi(str);
			else if (type == "i")
				_value_after_conversion = stoi(str);
			else if (type == "f")
				_value_after_conversion = stof(str);
			else if (type == "d")
				_value_after_conversion = stod(str);

			//FIXME:delete in the end of the project;
			// std::cout<<_value_after_conversion<<std::endl;
		}
		eOperand( void ) {};
		~eOperand( void ) {};
		eOperand &operator=(eOperand const &rhs)
		{
			if (this != &rhs)
			{
				this->_value = rhs._value;
				this->_value_after_conversion = rhs._value_after_conversion;
			}
				// std::cout << this->_value_after_conversion << std::endl;
			return *this;
		}
		eOperand(eOperand const &src)
		{
			// std::cout << _value_after_conversion << std::endl;
			*this = src;
		}

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

		// int0, float7 ,double16;

		// str::strstream -> set precision st to string;

		IOperand const *operator+(IOperand const &rhs) const
		{
			long long int 		var1 = std::stoll(this->toString());
			long long int 		var2 = std::stoll(rhs.toString());

			// std::cout << var1 << std::endl;
			// std::cout << var2 << std::endl;


			long long int 		add = var1 + var2;

			const std::string buf1 = std::to_string(add);

			// eOperand sum = eOperand<T>(buf);


			//TODO:add the data type flag to the factory class;
			return (new eOperand<T>(buf1));
		}
		// IOperand const *operator-(IOperand const &rhs) const;
		// IOperand const *operator*(IOperand const &rhs) const;
		// IOperand const *operator/(IOperand const &rhs) const;
		// IOperand const *operator%(IOperand const &rhs) const;

		std::string const &toString(void) const
		{
			return ( _value );
		}
		
	// private:
		std::string		_value;
		T				_value_after_conversion;
};

#endif
