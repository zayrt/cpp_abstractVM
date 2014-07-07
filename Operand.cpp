//
// Operand.cpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:30:25 2014 ilyas zelloufi
// Last update Mon Jul  7 12:30:26 2014 ilyas zelloufi
//

#include "Operand.hpp"

bool	reverse;

template <typename Type>
Operand<Type>::Operand(const String &str, const eOperandType &type) : _nb(0), _str(str), _type(type)
{
	Stringstream	ss(str);
	double				nb;

	ss >> nb;
	this->_nb = (Type)nb;
}

template <typename Type>
Operand<Type>::~Operand(void)
{}

template <typename Type>
String const	&Operand<Type>::toString(void) const
{
	return (this->_str);
}

template <typename Type>
int						Operand<Type>::getPrecision(void) const
{
	return ((int)this->_type);
}

template <typename Type>
eOperandType	Operand<Type>::getType(void) const
{
	return (this->_type);
}

template <typename Type>
IOperand				*Operand<Type>::operator+(const IOperand &rhs) const
{
	Stringstream	ss;
	double				nb, nb1, nb2;

	if (rhs.getPrecision() > this->getPrecision())
		return (rhs.operator+(*this));
	ss.str(this->toString());
	ss >> nb1;
	ss.clear();
	ss.str(rhs.toString());
	ss >> nb2;
	nb = (Type)(nb1 + nb2);
	ss.clear();
	ss << nb;
	return (new Operand<Type>(ss.str(), this->_type));
}

template <typename Type>
IOperand				*Operand<Type>::operator-(const IOperand &rhs) const
{
	Stringstream	ss;
	double				nb, nb1, nb2;

	if (rhs.getPrecision() > this->getPrecision())
	{
		reverse = true;
		return (rhs.operator-(*this));
	}
	ss.str(this->toString());
	ss >> nb1;
	ss.clear();
	ss.str(rhs.toString());
	ss >> nb2;
	if (reverse)
		nb = (Type)(nb2 - nb1);
	else
		nb = (Type)(nb1 - nb2);
	ss.clear();
	ss << nb;
	reverse = false;
	return (new Operand<Type>(ss.str(), this->_type));
}

template <typename Type>
IOperand				*Operand<Type>::operator*(const IOperand &rhs) const
{
	Stringstream	ss;
	double				nb, nb1, nb2;

	if (rhs.getPrecision() > this->getPrecision())
		return (rhs.operator*(*this));
	ss.str(this->toString());
	ss >> nb1;
	ss.clear();
	ss.str(rhs.toString());
	ss >> nb2;
	nb = (Type)(nb1 * nb2);
	ss.clear();
	ss << nb;
	return (new Operand<Type>(ss.str(), this->_type));
}

template <typename Type>
IOperand				*Operand<Type>::operator/(const IOperand &rhs) const
{
	Stringstream	ss;
	double				nb, nb1, nb2;

	if (rhs.getPrecision() > this->getPrecision())
	{
		reverse = true;
		return (rhs.operator/(*this));
	}
	ss.str(this->toString());
	ss >> nb1;
	ss.clear();
	ss.str(rhs.toString());
	ss >> nb2;
	if (reverse)
	{
		if (nb1 == 0)
			throw (Exception("division by 0"));
		nb = (Type)(nb2 / nb1);
	}
	else
	{
		if (nb2 == 0)
			throw (Exception("division by 0"));
		nb = (Type)(nb1 / nb2);
	}
	ss.clear();
	ss << nb;
	reverse = false;
	return (new Operand<Type>(ss.str(), this->_type));
}

template <>
IOperand	*Operand<float>::operator%(const IOperand &rhs) const
{
	(void) rhs;
	throw (Exception("modulo by float"));
}

template <>
IOperand	*Operand<double>::operator%(const IOperand &rhs) const
{
	(void) rhs;
	throw (Exception("modulo by double"));
}

template <typename Type>
IOperand				*Operand<Type>::operator%(const IOperand &rhs) const
{
	Stringstream	ss;
	double				nb, nb1, nb2;

	if (rhs.getPrecision() > this->getPrecision())
	{
		reverse = true;
		return (rhs.operator%(*this));
	}
	ss.str(this->toString());
	ss >> nb1;
	ss.clear();
	ss.str(rhs.toString());
	ss >> nb2;
	if (reverse)
	{
		if (nb1 == 0)
			throw (Exception("modulo by 0"));
		nb = (Type)((int)nb2 % (int)nb1);
	}
	else
	{
		if (nb2 == 0)
			throw (Exception("modulo by 0"));
		nb = (Type)((int)nb1 % (int)nb2);
	}
	ss.clear();
	ss << nb;
	reverse = false;
	return (new Operand<Type>(ss.str(), this->_type));
}
