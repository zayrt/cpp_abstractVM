//
// Exception.hpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:30:04 2014 ilyas zelloufi
// Last update Mon Jul  7 12:30:05 2014 ilyas zelloufi
//

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

typedef std::string				String;
typedef std::stringstream	Stringstream;

class Exception : public std::exception
{
protected:
	std::string	_msg;

public:
	Exception(String const &msg) throw ();
	virtual ~Exception(void) throw ();

	virtual const char	*what(void) const throw ();
};

#endif
