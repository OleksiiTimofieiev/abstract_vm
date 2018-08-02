#include "eOperand.hpp"

//TODO:// 	// int0, float7 ,double14; str::strstream -> set precision st to string;
//TODO:: not a value;
	//TODO::check input value;

template <class T> eOperand<T>::eOperand(const std::string &str) : _value(str)
{
	if (typeid(T) == typeid(int8_t))
		_value_after_conversion = stoi(str);
	else if (typeid(T) == typeid(int16_t))
		_value_after_conversion = stoi(str);
	else if (typeid(T) == typeid(int32_t))
		_value_after_conversion = stoi(str);
	else if (typeid(T) == typeid(float))
		_value_after_conversion = stof(str);
	else if (typeid(T) == typeid(double))
		_value_after_conversion = stod(str);
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
	if (typeid(T) == typeid(int8_t))
		return(0);
	else if (typeid(T) == typeid(int16_t))
		return(0);
	else if (typeid(T) == typeid(int32_t))
		return(0);
	else if (typeid(T) == typeid(float))
		return(7);
	else if (typeid(T) == typeid(double))
		return(14);
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
	long long int var1 = std::stoll(this->toString()); // value;
	long long int var2 = std::stoll(rhs.toString());

	// std::cout << var1 << std::endl;
	// std::cout << var2 << std::endl;

	long long int add = var1 + var2;

	const std::string new_line = std::to_string(add);

	eOperandType eNum;

	eNum = Int8;

	return (Factory().createOperand(eNum, new_line));
}
// template <class T> IOperand const *eOperand<T>::operator-(IOperand const &rhs) const
// template <class T> IOperand const *eOperand<T>::operator*(IOperand const &rhs) const
// template <class T> IOperand const *eOperand<T>::operator/(IOperand const &rhs) const
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
