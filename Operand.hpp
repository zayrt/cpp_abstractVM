//
// Operand.hpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:30:37 2014 ilyas zelloufi
// Last update Mon Jul  7 12:30:38 2014 ilyas zelloufi
//

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"

template <typename Type>
class	Operand : public IOperand
{
protected:
	Type		_nb;
	String		_str;
	eOperandType	_type;

public:
	Operand(const String &str, const eOperandType &type);
	~Operand(void);

	String const	&toString(void) const;
	int						getPrecision(void) const;
	eOperandType	getType(void) const;
	IOperand			*operator+(const IOperand &rhs) const;
	IOperand			*operator-(const IOperand &rhs) const;
	IOperand			*operator*(const IOperand &rhs) const;
	IOperand			*operator/(const IOperand &rhs) const;
	IOperand			*operator%(const IOperand &rhs) const;
};

template class Operand<char>;
template class Operand<short>;
template class Operand<int>;
template class Operand<float>;
template class Operand<double>;

#endif
