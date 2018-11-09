#include "pch.h"
#include "Command.h"
#include "DefaultAction.h"


Command::~Command()
{
	delete action;
}

Command::Command(AbstractAction* action, std::string description, std::string command, std::string parent_path):
	AbstractMenuItem(description, command, parent_path)
{
	this->action = action;
}

void Command::run()
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

