#include "pch.h"
#include "MenuCommand.h"
#include "DefaultAction.h"


MenuCommand::~MenuCommand()
{
	delete action;
}

MenuCommand::MenuCommand(AbstractAction* action, std::string description, std::string command) : AbstractMenuItem(description, command)
{
	this->action = action;
}

void MenuCommand::run()
{
	if(action != nullptr)
	{
		action->perform_action();
	}
	else
	{
		(new DefaultAction())->perform_action();
	}

}

