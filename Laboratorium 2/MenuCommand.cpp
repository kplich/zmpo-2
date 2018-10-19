#include "pch.h"
#include "MenuCommand.h"


MenuCommand::MenuCommand()
{
}


MenuCommand::~MenuCommand()
{
}

void MenuCommand::run() const
{
	if(action != NULL)
	{
		action->run_action();
	}
	else
	{
		//TODO: some "empty command"??? WTF?
	}

}

