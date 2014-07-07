//
// abstractVM.cpp for  in /home/zellou_i/rendu/cpp_abstractvm
// 
// Made by ilyas zelloufi
// Login   <zellou_i@epitech.net>
// 
// Started on  Mon Jul  7 12:29:40 2014 ilyas zelloufi
// Last update Mon Jul  7 12:29:41 2014 ilyas zelloufi
//

#include "Parser.hpp"
#include "VMStack.hpp"

bool			parseCmd(String &cmd, VMStack *vmstack)
{
	size_t	sep;

	sep = cmd.find_first_of(" ");
	if (sep == String::npos)
		return (vmstack->call(cmd));
	else
		return (vmstack->call(cmd.substr(0, sep), cmd.substr(sep + 1)));
}

int				main(int ac, char **av)
{
	Parser	parse;
	VMStack	vmstack;
	bool		ifExit;

	try
	{
		if (ac == 2)
			parse.initFd(av[1]);
		else if (ac == 1)
			parse.initInput();
		else
			std::cerr <<  "avm: Usage : ./avm [file]" << std::endl;
		for (String cmd = parse.getCmd(); cmd != ""; cmd = parse.getCmd())
		{
			ifExit = parseCmd(cmd, &vmstack);
			if (ifExit)
				break ;
		}
		if (ifExit)
			std::cout << vmstack.getOutput();
		else
			throw (Exception("exit not found"));
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return (0);
}
