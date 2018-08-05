#include "eOperand.hpp"

template <class T> eOperand<T>::eOperand(T value): _value(value) 
{
	if (typeid(T) == typeid(int8_t))
		_str = std::to_string(value);
	else if (typeid(T) == typeid(int16_t))
		_str = std::to_string(value);
	else if (typeid(T) == typeid(int32_t))
		_str = std::to_string(value);
	else if (typeid(T) == typeid(float))
	{
		std::stringstream set(std::stringstream::out);
		set << std::setprecision(7) << value;
		_str = set.str();
	}
	else if (typeid(T) == typeid(double))
	{
		std::stringstream set(std::stringstream::out);
		set << std::setprecision(14) << value;
		_str = set.str();
	}
}
template <class T> eOperand<T>::eOperand(void) {}
template <class T> eOperand<T>::~eOperand(void) {}
template <class T> IOperand const& eOperand<T>::operator = (eOperand const &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_value = rhs._value;
	}
	return *this;
}
template <class T> eOperand<T>::eOperand(eOperand const &src)
{
	*this = src;
}

template <class T> int eOperand<T>::getPrecision(void) const
{
	if ( typeid(T) == typeid(int8_t) )       	{ return(0); }
	else if ( typeid(T) == typeid(int16_t) ) 	{ return(0); }
	else if ( typeid(T) == typeid(int32_t) ) 	{ return(0); }
	else if ( typeid(T) == typeid(float) )   	{ return(7); }
	else if ( typeid(T) == typeid(double) )  	{ return(14); }
	else { return (0); }
}
template <class T> eOperandType eOperand<T>::getType(void) const
{
	if ( typeid(T) == typeid(int8_t) ) 			{ return(Int8); }
	else if ( typeid(T) == typeid(int16_t) ) 	{ return(Int16); }
	else if ( typeid(T) == typeid(int32_t) ) 	{ return(Int32); }
	else if ( typeid(T) == typeid(float) ) 		{ return(Float); }
	else if ( typeid(T) == typeid(double) ) 	{ return(Double); }
	else 										{ return (default_str); }
}

template <class T> IOperand const *eOperand<T>::operator + (IOperand const &rhs) const
{
	eOperandType	eNum = default_str;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value) + std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value) + std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator - (IOperand const &rhs) const
{
	eOperandType	eNum = default_str;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value) - std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value) - std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator * (IOperand const &rhs) const
{
	eOperandType	eNum = default_str;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value) * std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value) * std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator / (IOperand const &rhs) const
{
	eOperandType	eNum = default_str;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value) / std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value) / std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator % (IOperand const &rhs) const
{
	eOperandType	eNum = default_str;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value) % std::stoll(rhs.toString()));
	else
		new_line = std::to_string(fmod(static_cast<long double>(this->_value), std::stold(rhs.toString())));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> bool eOperand<T>::operator == (IOperand const &rhs) const
{
		eOperandType	eNum = default_str;

		if (this->getType() >= rhs.getType())
			eNum = this->getType();
		else
			eNum = rhs.getType();

		if (eNum < Float)
			return (static_cast<int32_t>(_value) == std::stoi(rhs.toString()));
		else if (eNum == Float)
			return (static_cast<float>(_value) == std::stof(rhs.toString()));
		else
			return (static_cast<double>(_value) == std::stod(rhs.toString()));
}

template <class T> bool eOperand<T>::operator > (IOperand const &rhs) const
{
		eOperandType	eNum = default_str;

		if (this->getType() >= rhs.getType())
			eNum = this->getType();
		else
			eNum = rhs.getType();

		if (eNum < Float)
			return (static_cast<int32_t>(_value) > std::stoi(rhs.toString()));
		else if (eNum == Float)
			return (static_cast<float>(_value) > std::stof(rhs.toString()));
		else
			return (static_cast<double>(_value) > std::stod(rhs.toString()));
}

template <class T> bool eOperand<T>::operator < (IOperand const &rhs) const
{
		eOperandType	eNum = default_str;

		if (this->getType() >= rhs.getType())
			eNum = this->getType();
		else
			eNum = rhs.getType();

		if (eNum < Float)
			return (static_cast<int32_t>(_value) < std::stoi(rhs.toString()));
		else if (eNum == Float)
			return (static_cast<float>(_value) < std::stof(rhs.toString()));
		else
			return (static_cast<double>(_value) < std::stod(rhs.toString()));
}

template <class T> std::string const &eOperand<T>::toString(void) const
{
	return (_str);
}

template class eOperand<int8_t>;
template class eOperand<int16_t>;
template class eOperand<int32_t>;
template class eOperand<float>;
template class eOperand<double>;
