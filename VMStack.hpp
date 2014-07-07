//
// VMStack.hpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:31:30 2014 ilyas zelloufi
// Last update Mon Jul  7 12:31:31 2014 ilyas zelloufi
//

#ifndef VMStack_HPP
#define VMStack_HPP

#include "Operand.hpp"

class	VMStack
{
protected:
	std::stack<IOperand *>	_stack;
	void										(VMStack::*_callFunctions[8])(void);
	IOperand								*(VMStack::*_createFunctions[5])(const String &) const;
	Stringstream						_cout;

public:
	VMStack(void);
	~VMStack(void);

	bool			call(const String &command, const String &operand = "");
	IOperand	*preCreateOperand(const String &operand) const;
	IOperand	*createOperand(eOperandType type, const String &value) const;
	String		getOutput(void) const;
protected:
	void			push(IOperand *param);
	void			pop(void);
	void			dump(void);
	void			assert(IOperand *param);
	void			add(void);
	void			sub(void);
	void			mul(void);
	void			div(void);
	void			mod(void);
	void			print(void);
	IOperand	*createInt8(const String &value) const;
	IOperand	*createInt16(const String &value) const;
	IOperand	*createInt32(const String &value) const;
	IOperand	*createFloat(const String &value) const;
	IOperand	*createDouble(const String &value) const;
	void			checkDec(String &value) const;
	void			checkNb(String &value) const;
};

#endif
