#include "pch.h"
#include "MenuCommand.h"


MenuCommand::MenuCommand()
{
}


MenuCommand::~MenuCommand()
{
}

MenuCommand::MenuCommand(VirtualAction* action, std::string description, std::string command) : VirtualMenuItem(description, command)
{
	this->action = action;
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

