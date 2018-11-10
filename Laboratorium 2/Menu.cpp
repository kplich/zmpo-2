#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <iterator>
#include "ReturnAction.h"
#include "input_output.h"
#include "SearchAction.h"

//TODO: this really shouldn't be here
static const std::string return_item_description = "Return to previous menu";
static const std::string return_item_command = "return";
static const std::string search_item_description = "Search in whole menu.";
static const std::string search_item_command = "search";

static const std::string available_items = "Available options:";
static const std::string no_item_found = "No option with given command found.";


Menu::Menu(std::string description, std::string command, Menu* root_menu, std::string parent_path):
	AbstractMenuItem(description, command, parent_path)
{
	//TODO: wrr, ugly!
	if (root_menu == nullptr)
	{
		this->root_menu = this;
	}
	else
	{
		this->root_menu = root_menu;
	}

	//this is deallocated in Menu destructor
	this->item_map = new std::map<std::string, AbstractMenuItem*>();

	//this is also deallocated in Menu destructor
	this->return_item = new Command(
		new ReturnAction(), //this is deallocated in MenuCommand destructor
		return_item_description,
		return_item_command,
		this->get_path()
	);

	this->search_item = new Command(
		new SearchAction(this->root_menu),
		search_item_description,
		search_item_command,
		this->get_path()
	);
}


Menu::Menu(std::map<std::string, AbstractMenuItem*>* item_map, std::string description, std::string command, Menu* root_menu, std::string parent_path):
	AbstractMenuItem(description, command, parent_path)
{
	//TODO: wrr, ugly!
	if (root_menu == nullptr)
	{
		this->root_menu = this;
	}
	else
	{
		this->root_menu = root_menu;
	}

	this->item_map = item_map;

	//deallocated in Menu destructor, 
	this->return_item = new Command(
		new ReturnAction(), //deallocated in MenuCommand destructor
		return_item_description,
		return_item_command,
		this->get_path()
	);
}

Menu::~Menu()
{
	std::map<std::string, AbstractMenuItem*>::iterator deleting_iterator = item_map->begin();

	while(deleting_iterator != item_map->end())
	{
		delete deleting_iterator->second;
		++deleting_iterator;
	}
	item_map->clear();

	delete return_item; //deallocate
	delete search_item;
	delete item_map;
}

void Menu::print_options()
{
	std::cout << "\n" << available_items << "\n";

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

	if (chosen_command == return_item_command)
	{
		return return_item;
	}
	
	if (chosen_command == search_item_command)
	{
		return search_item;
	}

	std::map<std::string, AbstractMenuItem*>::iterator find_iterator = item_map->find(chosen_command);

	if(find_iterator != item_map->end())
	{
		return find_iterator->second;
	}
	else
	{
		return nullptr;
	}
}

void Menu::search_for_command(std::string command_name, std::vector<std::string>* found_paths)
{
	std::map<std::string, AbstractMenuItem*>::iterator find_iterator = item_map->find(command_name);

	if (find_iterator != item_map->end())
	{
		found_paths->push_back(find_iterator->second->get_path());
	}

	std::map<std::string, AbstractMenuItem*>::iterator search_deeper_iterator = item_map->begin();

	while (search_deeper_iterator != item_map->end())
	{
		//from Wikipedia: "(...) the result of a static_cast from a pointer of a virtual base class to a pointer of a derived class is undefined."
		//we don't know, if the pointer from iterator points to a menu or a command,
		//so we use a dynamic conversion
		Menu* possible_menu_item = dynamic_cast<Menu*>(search_deeper_iterator->second);

		if (possible_menu_item != NULL)
		{
			possible_menu_item->search_for_command(command_name, found_paths);
		}

		++search_deeper_iterator;
	}
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
			std::cout << no_item_found << "\n";
		}
		else
		{
			chosen_item->run();
		}
		
	} while (chosen_item != return_item);
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
