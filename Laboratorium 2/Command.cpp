#include "pch.h"
#include "Command.h"
#include "DefaultAction.h"
#include "../ParsingStack/ParsingStack.h"

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
	std::string result;

	result += begin_command;
	result += begin_and_end_string;
	result += this->description;
	result += begin_and_end_string;
	result += separator;
	result += begin_and_end_string;
	result += this->command;
	result += begin_and_end_string;
	result += separator;
	result += begin_and_end_string;
	result += this->help;
	result += begin_and_end_string;
	result += end_command;

	return result;
}

