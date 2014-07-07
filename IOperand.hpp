//
// IOperand.hpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:30:12 2014 ilyas zelloufi
// Last update Mon Jul  7 12:30:13 2014 ilyas zelloufi
//

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include "Exception.hpp"

enum	eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

class	IOperand
{
public:
	virtual ~IOperand(void) {}

	virtual String const	&toString(void) const = 0;
	virtual int						getPrecision(void) const = 0;
	virtual eOperandType	getType(void) const = 0;
	virtual IOperand			*operator+(const IOperand &rhs) const = 0;
	virtual IOperand			*operator-(const IOperand &rhs) const = 0;
	virtual IOperand			*operator*(const IOperand &rhs) const = 0;
	virtual IOperand			*operator/(const IOperand &rhs) const = 0;
	virtual IOperand			*operator%(const IOperand &rhs) const = 0;
};

#endif
