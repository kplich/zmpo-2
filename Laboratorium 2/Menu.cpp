#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <iterator>
#include "ReturnAction.h"
#include "input_output.h"

/**
 * Description of a return item for this menu.
 */
static const std::string return_item_description = "Return from current menu";

/**
 * Command triggering a return item for this menu.
 */
static const std::string return_item_command = "return";

Menu::Menu(std::string description, std::string command):
	VirtualMenuItem(description, command)
{
	this->item_map = new std::map<std::string, VirtualMenuItem*>();
	this->return_command_object = new MenuCommand(
		new ReturnAction(),
		return_item_description,
		return_item_command
	);

	insert_item_into_map(item_map, return_command_object);

	std::cout << "Not-map parametrized Menu constructor, " << command << "\n";
}


Menu::Menu(std::map<std::string, VirtualMenuItem*>* item_map, std::string description, std::string command):
	VirtualMenuItem(description, command)
{
	this->item_map = item_map;
	this->return_command_object = new MenuCommand(new ReturnAction(), "Return to previous menu", "return");
	insert_item_into_map(item_map, return_command_object);;

	std::cout << "Map parametrized Menu constructor, " << command << "\n";
}

Menu::~Menu()
{
	std::cout << "Menu Destructor, " << command << "\n";

	std::map<std::string, VirtualMenuItem*>::iterator destructing_iterator = item_map->begin();

	for (; destructing_iterator != item_map->end(); ++destructing_iterator)
	{
		delete destructing_iterator->second;
	}
}

void Menu::print_options()
{
	std::cout << "\nAvailable options:\n";

	std::map<std::string, VirtualMenuItem*>::iterator temp_iterator = item_map->begin();

	for ( ; temp_iterator != item_map->end(); ++temp_iterator)
	{
		std::cout << temp_iterator->second->get_description() << ":\t" << temp_iterator->first << "\n";
	}

	std::cout << "\n";
}

VirtualMenuItem* Menu::choose_option()
{
	std::string chosen_command = get_user_input();

	std::map<std::string, VirtualMenuItem*>::iterator found_pair = item_map->find(chosen_command);

	if(found_pair != item_map->end())
	{
		return found_pair->second;
	}
	else
	{
		return nullptr;
	}
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
		
	} while (chosen_item != return_command_object);
}

void Menu::add_new_item(VirtualMenuItem* new_item)
{
	insert_item_into_map(item_map, new_item);
}

void Menu::delete_item(std::string)
{
	//TODO: implement!
}

void Menu::insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item)
{
	item_map->insert(std::pair<std::string, VirtualMenuItem*>(menu_item->get_command(), menu_item));
}
