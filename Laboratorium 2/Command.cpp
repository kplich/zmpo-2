#include "pch.h"
#include "Command.h"
#include "DefaultAction.h"

static const char begin_and_end_string = '\'';
static const char begin_command = '[';
static const char separator = ',';
static const char end_command = ']';

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

std::string Command::to_string()
{
	return "" +
		begin_command +
		begin_and_end_string +
		this->description +
		begin_and_end_string +
		separator +
		begin_and_end_string +
		this->command +
		begin_and_end_string +
		separator +
		begin_and_end_string +
		this->help +
		begin_and_end_string +
		end_command;
}

