//
// Exception.cpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:29:50 2014 ilyas zelloufi
// Last update Mon Jul  7 12:29:51 2014 ilyas zelloufi
//

#include "Exception.hpp"

Exception::Exception(String const &msg) throw () : _msg(msg)
{}

Exception::~Exception(void) throw ()
{}

const char	*Exception::what(void) const throw ()
{
	return (this->_msg.c_str());
}
