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
	std::string user_input = get_user_input();

	//deallocated at the end of the method
	std::map<std::string, AbstractMenuItem*>* paths_and_items_found = new std::map<std::string, AbstractMenuItem*>();
	root_menu->search_for_command(user_input, paths_and_items_found);


	std::map<std::string, AbstractMenuItem*>::iterator found_items = paths_and_items_found->begin();
	while(found_items != paths_and_items_found->end())
	{
		std::cout << found_items->first << "\n";
	}

	delete paths_and_items_found;
}

