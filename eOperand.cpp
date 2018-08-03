#include "eOperand.hpp"

#include				<sstream>
#include				<iomanip>
#include				<string>

//TODO:: check input value;

template <class T> eOperand<T>::eOperand(const std::string &str) 
{
	if (typeid(T) == typeid(int8_t))
	{
		_value = str;
		_value_after_conversion = static_cast<int8_t>(stoi(str));
	}
	else if (typeid(T) == typeid(int16_t))
	{
		_value = str;
		_value_after_conversion = static_cast<int16_t>(stoi(str));
	}
	else if (typeid(T) == typeid(int32_t))
	{
		_value = str;
		_value_after_conversion = stoi(str);
	}
	else if (typeid(T) == typeid(float))
	{
		std::stringstream set(std::stringstream::out);
		set << std::setprecision(7) << str;
		_value = set.str();
		_value_after_conversion = stof(_value);
	}
	else if (typeid(T) == typeid(double))
	{
		std::stringstream set(std::stringstream::out);
		set << std::setprecision(14) << str;
		_value = set.str();
		_value_after_conversion = stod(_value);
	}
}
template <class T> eOperand<T>::eOperand(void) {}
template <class T> eOperand<T>::~eOperand(void) {}
template <class T> IOperand const& eOperand<T>::operator = (eOperand const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs._value;
		this->_value_after_conversion = rhs._value_after_conversion;
	}
	return *this;
}
template <class T> eOperand<T>::eOperand(eOperand const &src)
{
	*this = src;
}

template <class T> int eOperand<T>::getPrecision(void) const
{
	if (typeid(T) == typeid(int8_t)) { return(0); }
	else if (typeid(T) == typeid(int16_t)) { return(0); }
	else if (typeid(T) == typeid(int32_t)) { return(0); }
	else if (typeid(T) == typeid(float)) { return(7); }
	else if (typeid(T) == typeid(double)) { return(14); }

	return (0);
}
template <class T> eOperandType eOperand<T>::getType(void) const
{
	if (typeid(T) == typeid(int8_t))
		return(Int8);
	else if (typeid(T) == typeid(int16_t))
		return(Int16);
	else if (typeid(T) == typeid(int32_t))
		return(Int32);
	else if (typeid(T) == typeid(float))
		return(Float);
	else if (typeid(T) == typeid(double))
		return(Double);
	return (default_value);
}

template <class T> IOperand const *eOperand<T>::operator+(IOperand const &rhs) const
{
	eOperandType	eNum = default_value;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value_after_conversion) + std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value_after_conversion) + std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator-(IOperand const &rhs) const
{
	eOperandType	eNum = default_value;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value_after_conversion) - std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value_after_conversion) - std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator*(IOperand const &rhs) const
{
	eOperandType	eNum = default_value;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value_after_conversion) * std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value_after_conversion) * std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}

template <class T> IOperand const *eOperand<T>::operator/(IOperand const &rhs) const
{
	eOperandType	eNum = default_value;
	std::string		new_line;

	if (this->getType() >= rhs.getType())
		eNum = this->getType();
	else
		eNum = rhs.getType();

	if (eNum < Float)
		new_line = std::to_string(static_cast<int64_t>(this->_value_after_conversion) / std::stoll(rhs.toString()));
	else
		new_line = std::to_string(static_cast<long double>(this->_value_after_conversion) / std::stold(rhs.toString()));

	return (Factory().createOperand(eNum, new_line));
}
// template <class T> IOperand const *eOperand<T>::operator%(IOperand const &rhs) const

template <class T>std::string const &eOperand<T>::toString(void) const
{
	return (_value);
}

template class eOperand<int8_t>;
template class eOperand<int16_t>;
template class eOperand<int32_t>;
template class eOperand<float>;
template class eOperand<double>;
