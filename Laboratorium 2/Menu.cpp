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

	//TODO: make this MenuCommand a constant
	insert_item_into_map(item_map, return_command);
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
	VirtualMenuItem* chosen_item;

	do
	{
		print_options();
		chosen_item = choose_option();

		if (chosen_item == nullptr)
		{
			std::cout << "No option with given command found.\n";
		}
		else
		{
			chosen_item->run();
		}
		
	} while (chosen_item != return_command);
}
