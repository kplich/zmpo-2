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

Command* Command::parse_command(ParsingStack* input, std::string parent_path)
{
	std::string description;
	std::string command;
	std::string help;

	if(input->pop_equal_to(begin_command)) //parse beginning of command '['
	{
		if(input->pop_equal_to(begin_and_end_string)) //parse beginning of string '\''
		{
			//parse description
			description = input->pop_until_char_found(begin_and_end_string);

			if(input->pop_equal_to(separator)) //parse separator ','
			{
				if(input->pop_equal_to(begin_and_end_string)) //parse beginning of string '\''
				{
					//parse command
					command = input->pop_until_char_found(begin_and_end_string);

					if(input->pop_equal_to(separator)) //parse separator ','
					{
						if(input->pop_equal_to(begin_and_end_string)) //parse beginning of string '\''
						{
							help = input->pop_until_char_found(begin_and_end_string);

							if(input->pop_equal_to(end_command)) //parse end of command ']'
							{
								return new Command(
									description,
									command,
									parent_path,
									new DefaultAction,
									help
								);
							}
						}
					}
				}
			}
		}
	}

	return nullptr;
}

