#include "pch.h"
#include "utility.h"
#include "VirtualAction.h"
#include "Menu.h"
#include <iostream>
#include "actions.h"

//TODO: actions aren't really reusable!!!
VirtualMenuItem* get_main_menu(std::vector<Table*>* table_vector)
{
	VirtualMenuItem* add_table = new MenuCommand(
		new AddTable(table_vector),
		"Add a new table",
		"add"
	);

	VirtualMenuItem* print_table = new MenuCommand(
		new PrintTable(table_vector),
		"Print one of the tables",
		"print_one"
	);

	std::map<std::string, VirtualMenuItem*>* main_menu_map = new std::map<std::string, VirtualMenuItem*>();

	insert_item_into_map(main_menu_map, add_table);
	insert_item_into_map(main_menu_map, print_table);

	//TODO: lol, wtf can't this be of type VirtualMenuItem???
	VirtualMenuItem* main_menu = new Menu(main_menu_map, "Open main menu", "main_menu");

	return main_menu;
}

void insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item)
{
	item_map->insert(std::pair<std::string, VirtualMenuItem*>(menu_item->get_command(), menu_item));
}

std::string get_input_from_user()
{
	std::string result;
	std::getline(std::cin, result);
	return result;
}
