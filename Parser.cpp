//
// Parser.cpp for Parser in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:30:52 2014 ilyas zelloufi
// Last update Mon Jul  7 12:30:53 2014 ilyas zelloufi
//

#include "Parser.hpp"

Parser::Parser(void)
{}

Parser::~Parser(void)
{}

void			Parser::initInput()
{
  String	tmp("");

	while (42)
	{
		std::getline(std::cin, tmp);
		std::size_t end = tmp.find(";;");
		std::size_t found = tmp.find_first_of(";");
		if (found != String::npos)
			tmp = tmp.substr(0, found);
		if (!tmp.empty())
			this->cmd.push_back(tmp);
		if (std::cin.eof() || end != String::npos)
			break ;
	}
}

void						Parser::initFd(char *file)
{
  std::ifstream	fd;

	if (file != NULL)
	{
		fd.open(file);
		if (fd)
		{
			String	line;
			while (getline(fd, line))
			{
				std::size_t found = line.find_first_of(";");
				if (found != String::npos)
					line = line.substr(0, found);
				if (!line.empty())
					this->cmd.push_back(line);
			}
		}
		fd.close();
	}
}

void														Parser::showAllCmd()
{
	std::vector<String>::iterator	it = this->cmd.begin();

	while (it != this->cmd.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

String		Parser::getCmd(void)
{
	String	cmd;

	if (!this->cmd.empty())
	{
		cmd = this->cmd.front();
		this->cmd.erase(this->cmd.begin());
		return (cmd);
	}
	return ("");
}
