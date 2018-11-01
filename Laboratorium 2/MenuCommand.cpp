#include "pch.h"
#include "MenuCommand.h"
#include <iostream>
#include "DefaultAction.h"


MenuCommand::~MenuCommand()
{
	std::cout << "MenuCommand destructor, " << command << "\n";

	delete action;
}

MenuCommand::MenuCommand(AbstractAction* action, std::string description, std::string command) : AbstractMenuItem(description, command)
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
		(new DefaultAction())->perform_action();
	}

}

