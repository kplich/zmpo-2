#include "pch.h"
#include "MenuCommand.h"
#include <iostream>


MenuCommand::MenuCommand()
{
}


MenuCommand::~MenuCommand()
{
	std::cout << "MenuCommand destructor, " << command << "\n";
}

MenuCommand::MenuCommand(VirtualAction* action, std::string description, std::string command) : VirtualMenuItem(description, command)
{
	this->action = action;

	std::cout << "Parametrized MenuCommand constructor, " << command << "\n";
}

void MenuCommand::run()
{
	if(action != NULL)
	{
		action->perform_action();
	}
	else
	{
		//TODO: some "empty command"??? WTF?
	}

}

