#include "pch.h"
#include "Command.h"
#include "DefaultAction.h"


Command::~Command()
{
	delete action;
}

Command::Command(std::string description, std::string command, std::string parent_path, AbstractAction* action, std::string help):
	AbstractMenuItem(description, command, parent_path)
{
	this->action = action;
	this->help = help;
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

std::string Command::get_help()
{
	return help;
}


