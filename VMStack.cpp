//
// VMStack.cpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:31:04 2014 ilyas zelloufi
// Last update Mon Jul  7 12:31:19 2014 ilyas zelloufi
//

#include "VMStack.hpp"

String	types[5] =
{
	"int8",
	"int16",
	"int32",
	"float",
	"double"
};

String	commands[8] =
{
	"pop",
	"dump",
	"add",
	"sub",
	"mul",
	"div",
	"mod",
	"print"
};

VMStack::VMStack(void)
{
	this->_callFunctions[0] = &VMStack::pop;
	this->_callFunctions[1] = &VMStack::dump;
	this->_callFunctions[2] = &VMStack::add;
	this->_callFunctions[3] = &VMStack::sub;
	this->_callFunctions[4] = &VMStack::mul;
	this->_callFunctions[5] = &VMStack::div;
	this->_callFunctions[6] = &VMStack::mod;
	this->_callFunctions[7] = &VMStack::print;
	this->_createFunctions[0] = &VMStack::createInt8;
	this->_createFunctions[1] = &VMStack::createInt16;
	this->_createFunctions[2] = &VMStack::createInt32;
	this->_createFunctions[3] = &VMStack::createFloat;
	this->_createFunctions[4] = &VMStack::createDouble;
}

VMStack::~VMStack(void)
{}

bool	VMStack::call(const String &command, const String &operand)
{
	int	i;

	if (command == "push")
		this->push(this->preCreateOperand(operand));
	else if (command == "assert")
		this->assert(this->preCreateOperand(operand));
	else if (command == "exit")
		return (true);
	else
	{
		for (i = 0; i < 9; ++i)
			if (commands[i] == command)
				break ;
		if (i == 9)
			throw (Exception("the instruction doesn't exist"));
		else
			(this->*_callFunctions[i])();
	}
	return (false);
}

IOperand	*VMStack::preCreateOperand(const String &operand) const
{
	size_t	first;
	size_t	last;
	String	type;
	String	value;
	int			i;

	first = operand.find_first_of('(');
	last = operand.find_last_of(')');
	if (!first || !last || first > last || last == first + 1)
			throw (Exception("incorrect syntax"));
	type = operand.substr(0, first);
	value = operand.substr(first + 1, last - first - 1);
	if (type == "float" || type == "double")
		this->checkDec(value);
	else
		this->checkNb(value);
	for (i = 0; i < 5; ++i)
		if (types[i] == type)
			break ;
	if (i == 5)
		throw (Exception("the type doesn't exist"));
	return (this->createOperand((eOperandType)i, value));
}

IOperand	*VMStack::createOperand(eOperandType type, const String &value) const
{
	return ((this->*_createFunctions[type])(value));
}

String		VMStack::getOutput(void) const
{
	return (this->_cout.str());
}

void	VMStack::push(IOperand *param)
{
	this->_stack.push(param);
}

void	VMStack::pop(void)
{
	if (this->_stack.empty())
		throw (Exception("pop on empty stack"));
	this->_stack.pop();
}

void	VMStack::dump(void)
{
	for (std::stack<IOperand *>	tmp = this->_stack; !tmp.empty(); tmp.pop())
		this->_cout << tmp.top()->toString() << std::endl;
}

void				VMStack::assert(IOperand *param)
{
	IOperand	*top;

	if (!this->_stack.empty())
	{
		top = this->_stack.top();
		if ((top->toString() == param->toString()) && (top->getPrecision() == param->getPrecision()))
			return ;
	}
	throw (Exception("assert fail"));
}

void				VMStack::add(void)
{
	IOperand	*operand1;
	IOperand	*operand2;

	if (!this->_stack.empty())
	{
		operand1 = this->_stack.top();
		this->_stack.pop();
		if (!this->_stack.empty())
		{
			operand2 = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(*operand1 + *operand2);
			delete (operand1);
			delete (operand2);
			return ;
		}
	}
	throw (Exception("add fail without two parameters in stack"));
}

void				VMStack::sub(void)
{
	IOperand	*operand1;
	IOperand	*operand2;

	if (!this->_stack.empty())
	{
		operand1 = this->_stack.top();
		this->_stack.pop();
		if (!this->_stack.empty())
		{
			operand2 = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(*operand1 - *operand2);
			delete (operand1);
			delete (operand2);
			return ;
		}
	}
	throw (Exception("sub fail without two parameters in stack"));
}

void				VMStack::mul(void)
{
	IOperand	*operand1;
	IOperand	*operand2;

	if (!this->_stack.empty())
	{
		operand1 = this->_stack.top();
		this->_stack.pop();
		if (!this->_stack.empty())
		{
			operand2 = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(*operand1 * *operand2);
			delete (operand1);
			delete (operand2);
			return ;
		}
	}
	throw (Exception("mul fail without two parameters in stack"));
}

void				VMStack::div(void)
{
	IOperand	*operand1;
	IOperand	*operand2;

	if (!this->_stack.empty())
	{
		operand1 = this->_stack.top();
		this->_stack.pop();
		if (!this->_stack.empty())
		{
			operand2 = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(*operand1 / *operand2);
			delete (operand1);
			delete (operand2);
			return ;
		}
	}
	throw (Exception("div fail without two parameters in stack"));
}

void				VMStack::mod(void)
{
	IOperand	*operand1;
	IOperand	*operand2;

	if (!this->_stack.empty())
	{
		operand1 = this->_stack.top();
		this->_stack.pop();
		if (!this->_stack.empty())
		{
			operand2 = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(*operand1 % *operand2);
			delete (operand1);
			delete (operand2);
			return ;
		}
	}
	throw (Exception("mod fail without two parameters in stack"));
}

void				VMStack::print(void)
{
	IOperand			*top;
	Stringstream	ss;
	short					toPrint;

	if (!this->_stack.empty())
	{
		top = this->_stack.top();
		if (top->getType() == Int8)
		{
			ss.str(top->toString());
			ss >> toPrint;
			this->_cout << (char)toPrint << std::endl;
			return ;
		}
	}
	throw (Exception("print fail"));
}

IOperand	*VMStack::createInt8(const String &value) const
{
	return (new Operand<char>(value, Int8));
}

IOperand	*VMStack::createInt16(const String &value) const
{
	return (new Operand<short>(value, Int16));
}

IOperand	*VMStack::createInt32(const String &value) const
{
	return (new Operand<int>(value, Int32));
}

IOperand	*VMStack::createFloat(const String &value) const
{
	return (new Operand<float>(value, Float));
}

IOperand	*VMStack::createDouble(const String &value) const
{
	return (new Operand<double>(value, Double));
}

void	VMStack::checkDec(String &value) const
{
	int nb_point = 0;

	for (int i = 0; value[i]; ++i)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
			throw (Exception("the value isn't a decimal number"));
		if (value[i] == '.')
			++nb_point;
	}
	if (nb_point != 1)
		throw (Exception("the value isn't a decimal number"));
}

void	VMStack::checkNb(String &value) const
{
	int i = 0;

	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
			throw (Exception("the value isn't a number"));
		i += 1;
	}
}
