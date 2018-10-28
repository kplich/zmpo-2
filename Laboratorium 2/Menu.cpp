#include "pch.h"
#include "Menu.h"
#include <iostream>
#include "utility.h"
#include <iterator>


Menu::Menu()
{
}

Menu::Menu(std::map<std::string, VirtualMenuItem*>* item_map, std::string description, std::string command) : VirtualMenuItem(description, command)
{
	this->item_map = item_map;
}

Menu::~Menu()
{
}

void Menu::print_options()
{
	std::cout << "\nAvailable options:\n";

	std::map<std::string, VirtualMenuItem*>::iterator temp_iterator = item_map->begin();

	for ( ; temp_iterator != item_map->end(); ++temp_iterator)
	{
		std::cout << temp_iterator->second->get_description() << ":\t" << temp_iterator->first << "\n";
	}
}

VirtualMenuItem* Menu::choose_option()
{
	std::string chosen_command = get_input_from_user();

	return item_map->find(chosen_command)->second;
}


void Menu::run()
{
	print_options();

	VirtualMenuItem* chosen_item = choose_option();

	if (chosen_item != nullptr)
	{
		chosen_item->run();
	}
	else
	{
		//no command has been found, so the menu closes
		std::cout << "No option with given command has been found. Reverting back to main menu.\n";
	}
}
