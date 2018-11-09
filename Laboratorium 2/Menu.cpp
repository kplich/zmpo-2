#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <iterator>
#include "ReturnAction.h"
#include "input_output.h"
#include "SearchAction.h"

/**
 * Description of a return item for this menu.
 */
static const std::string return_item_description = "Return to previous menu";

/**
 * Command triggering a return item for this menu.
 */
static const std::string return_item_command = "return";

/**
 * Description of a search item for this menu.
 */
static const std::string search_item_description = "Search in whole menu.";

/**
 * Command triggering a search item for this menu.
 */
static const std::string search_item_command = "search";


Menu::Menu(std::string description, std::string command, Menu* root_menu, std::string parent_path):
	AbstractMenuItem(description, command, parent_path)
{
	//this is deallocated in Menu destructor
	this->item_map = new std::map<std::string, AbstractMenuItem*>();

	//this is also deallocated in Menu destructor
	this->return_command_object = new Command(
		new ReturnAction(), //this is deallocated in MenuCommand destructor
		return_item_description,
		return_item_command,
		this->get_path()
	);

	this->search_command_object = new Command(
		new SearchAction(root_menu),
		search_item_description,
		search_item_command,
		this->get_path()
	);

	//TODO: delete this
	insert_item_into_map(item_map, return_command_object);

	this->root_menu = root_menu;
}


Menu::Menu(std::map<std::string, AbstractMenuItem*>* item_map, std::string description, std::string command, Menu* root_menu, std::string parent_path):
	AbstractMenuItem(description, command, parent_path)
{
	this->item_map = item_map;

	//deallocated in Menu destructor, 
	this->return_command_object = new Command(
		new ReturnAction(), //deallocated in MenuCommand destructor
		return_item_description,
		return_item_command,
		this->get_path()
	);

	//TODO: delete this
	insert_item_into_map(item_map, return_command_object);

	this->root_menu = root_menu;
}

Menu::~Menu()
{
	item_map->clear();

	delete return_command_object; //deallocate
	delete item_map;
}

void Menu::print_options()
{
	std::cout << "\nAvailable options:\n";

	std::map<std::string, AbstractMenuItem*>::iterator temp_iterator = item_map->begin();

	for ( ; temp_iterator != item_map->end(); ++temp_iterator)
	{
		std::cout << temp_iterator->second->get_description() << ":\t" << temp_iterator->first << "\n";
	}

	std::cout << "\n";
}

AbstractMenuItem* Menu::choose_option()
{
	//TODO: allow for choosing return, help and search
	std::string chosen_command = get_user_input();

	std::map<std::string, AbstractMenuItem*>::iterator found_pair = item_map->find(chosen_command);

	if(found_pair != item_map->end())
	{
		return found_pair->second;
	}
	else
	{
		return nullptr;
	}
}

void Menu::search_for_command(std::string command_name, std::map<std::string, AbstractMenuItem*>* item_map)
{
	//TODO: implement that
}


void Menu::run()
{
	std::cout << description << "\t" << command << "\n";

	AbstractMenuItem* chosen_item;

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

void Menu::add_item(AbstractMenuItem* new_item)
{
	insert_item_into_map(item_map, new_item);
}

void Menu::delete_item(std::string item_command)
{
	AbstractMenuItem* deleted_item = item_map->find(item_command)->second;

	item_map->erase(item_map->find(item_command));

	delete deleted_item;
}

void Menu::insert_item_into_map(std::map<std::string, AbstractMenuItem*>* item_map, AbstractMenuItem* menu_item)
{
	item_map->insert(std::pair<std::string, AbstractMenuItem*>(menu_item->get_command(), menu_item));
}
