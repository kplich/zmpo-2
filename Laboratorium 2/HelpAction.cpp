#include "pch.h"
#include "HelpAction.h"
#include <iostream>
#include "input_output.h"
#include "Command.h"

HelpAction::HelpAction(std::map<std::string, AbstractMenuItem*>* item_map)
{
	this->item_map = item_map;
}


HelpAction::~HelpAction()
{
}

void HelpAction::perform_action() const
{
	std::cout << "How can I help you? Type in the troublesome command.\n";

	std::string user_input = get_user_input();

	std::map<std::string, AbstractMenuItem*>::iterator find_iterator = item_map->find(get_user_input());

	if(find_iterator != item_map->end())
	{
		//found item doesn't have to be of type Command, so we attempt a cast
		Command* possible_command = dynamic_cast<Command*>(find_iterator->second);

		if (possible_command != nullptr) {
			std::cout << "Help for command " << user_input << ":\n";
			std::cout << possible_command->get_help();
		}
		else
		{
			std::cout << "No such command found.\n";
		}
	}
	else
	{
		std::cout << "No such command found.\n";
	}
}

