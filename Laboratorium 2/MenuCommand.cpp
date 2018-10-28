#include "pch.h"
#include "MenuCommand.h"


MenuCommand::MenuCommand()
{
}


MenuCommand::~MenuCommand()
{
}

MenuCommand::MenuCommand(VirtualAction* action)
{
	this->action = action;
}

void MenuCommand::run() const
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

