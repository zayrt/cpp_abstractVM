//
// Parser.hpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:32:02 2014 ilyas zelloufi
// Last update Mon Jul  7 12:32:04 2014 ilyas zelloufi
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Exception.hpp"

class	Parser
{
protected:
	std::vector<String>	cmd;

public:
	Parser(void);
	~Parser(void);

	void		initInput(void);
	void		initFd(char *file);
	void		showAllCmd(void);
	String	getCmd(void);
};

#endif
