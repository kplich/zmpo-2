#include "pch.h"
#include "SearchAction.h"
#include "input_output.h"
#include <iostream>


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


	if(paths_found->empty())
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

