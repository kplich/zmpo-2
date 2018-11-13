#include "pch.h"
#include "special_actions.h"
#include <iostream>
#include "input_output.h"

DefaultAction::DefaultAction()
{
}

DefaultAction::~DefaultAction()
{
}

void DefaultAction::perform_action() const
{
	std::cout << "Default action.\n";
}

//-------------------------------------------------------------------------------------

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

	std::map<std::string, AbstractMenuItem*>::iterator find_iterator = item_map->find(user_input);

	if (find_iterator != item_map->end())
	{
		//found item doesn't have to be of type Command, so we attempt a cast
		Command* possible_command = dynamic_cast<Command*>(find_iterator->second);

		if (possible_command != nullptr) {
			std::cout << "Help for command " << user_input << ":\n";
			std::cout << possible_command->get_help() << "\n";
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

//------------------------------------------------------------------------------------------------------------

//TODO: just delete that?
ReturnAction::ReturnAction() = default;

ReturnAction::~ReturnAction()
{
}

void ReturnAction::perform_action() const
{
	std::cout << "Returning to previous menu.\n";
}

//-----------------------------------------------------------------------------

SearchAction::SearchAction(Menu* root_menu)
{
	this->root_menu = root_menu;
}


SearchAction::~SearchAction()
{
}

void SearchAction::perform_action() const
{
	std::cout << "Enter the command to look for: \n";

	std::string user_input = get_user_input();

	//deallocated at the end of the method
	std::vector<std::string>* paths_found = new std::vector<std::string>();
	root_menu->search_for_command(user_input, paths_found);


	if (paths_found->empty())
	{
		std::cout << "No such command found.\n";
	}
	else
	{
		std::vector<std::string>::iterator paths_found_iterator = paths_found->begin();
		while (paths_found_iterator != paths_found->end())
		{
			std::cout << *paths_found_iterator << "\n";
			++paths_found_iterator;
		}
	}

	delete paths_found;
}

