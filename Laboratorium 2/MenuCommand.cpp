#include "pch.h"
#include "MenuCommand.h"
#include <iostream>


MenuCommand::~MenuCommand()
{
	std::cout << "MenuCommand destructor, " << command << "\n";

	delete action;
}

MenuCommand::MenuCommand(VirtualAction* action, std::string description, std::string command) : AbstractMenuItem(description, command)
{
	this->action = action;

	std::cout << "Parametrized MenuCommand constructor, " << command << "\n";
}

void MenuCommand::run()
{
	if(action != nullptr)
	{
		action->perform_action();
	}
	else
	{
		//TODO: some "empty command"??? WTF?
	}

}

