#include "eOperand.hpp"

//TODO:// 	// int0, float7 ,double16; str::strstream -> set precision st to string;
//TODO:: not a value;

template <class T> eOperand<T>::eOperand(const std::string &str) : _value(str)
{
	std::string type;

	type = typeid(T).name();

	//TODO::check input value;
	// if (typeid(T) == typeid(int8_t))//
	if (type == "a")
		_value_after_conversion = stoi(str);
	else if (type == "s")
		_value_after_conversion = stoi(str);
	else if (type == "i")
		_value_after_conversion = stoi(str);
	else if (type == "f")
		_value_after_conversion = stof(str);
	else if (type == "d")
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
	std::string type = typeid(T).name();

	if (type == "a")
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
template <class T> eOperandType eOperand<T>::getType(void) const
{
	std::string type = typeid(T).name();

	if (type == "a")
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
// IOperand const *operator-(IOperand const &rhs) const;
// IOperand const *operator*(IOperand const &rhs) const;
// IOperand const *operator/(IOperand const &rhs) const;
// IOperand const *operator%(IOperand const &rhs) const;

template <class T>std::string const &eOperand<T>::toString(void) const
{
	return (_value);
}


template class eOperand<int8_t>;
template class eOperand<int16_t>;
template class eOperand<int32_t>;
template class eOperand<float>;
template class eOperand<double>;
