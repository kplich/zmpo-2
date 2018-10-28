#include "pch.h"
#include "Menu.h"
#include <iostream>
#include "utility.h"


Menu::Menu()
{
}

Menu::Menu(std::vector<VirtualMenuItem*>* menu_items, std::string description, std::string command) : VirtualMenuItem(description, command)
{
	this->menu_items = menu_items;
	this->item_map = nullptr;
}

Menu::Menu(std::map<std::string, VirtualMenuItem*>* item_map, std::string description, std::string name) : VirtualMenuItem(description, command)
{
	this->menu_items = nullptr;
	this->item_map = item_map;
}

Menu::~Menu()
{
}

void Menu::print_options()
{
	std::cout << "Available options:\n";
	for (int i = 0; i<menu_items->size(); ++i)
	{
		std::cout << menu_items->at(i)->get_description() << ":\t" << menu_items->at(i)->get_command() << "\n";
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
