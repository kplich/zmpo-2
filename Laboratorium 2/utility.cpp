#include "pch.h"
#include "utility.h"
#include "VirtualAction.h"
#include "DummyAction2.h"
#include "Menu.h"
#include "DummyAction1.h"
#include "MenuCommand.h"
#include <iostream>

std::map<std::string, VirtualMenuItem*>* get_map_of_menu_items()
{
	VirtualAction* sub_action_1 = new DummyAction1();
	VirtualAction* sub_action_2 = new DummyAction2();

	VirtualMenuItem* command_1 = new MenuCommand(
		sub_action_1,
		"Performs action 1.",
		"action_1");

	VirtualMenuItem* command_2 = new MenuCommand(
		sub_action_2,
		"Performs action 2.",
		"action_2"
	);

	std::map<std::string, VirtualMenuItem*>* sub_menu_map = new std::map<std::string, VirtualMenuItem*>();

	insert_item_into_map(sub_menu_map, command_1);
	insert_item_into_map(sub_menu_map, command_2);

	VirtualMenuItem* sub_menu = new Menu(sub_menu_map, "Open sub-menu.", "sub_menu");


	std::map<std::string, VirtualMenuItem*>* menu_map = new std::map<std::string, VirtualMenuItem*>();

	insert_item_into_map(menu_map, command_1);
	insert_item_into_map(menu_map, command_2);
	insert_item_into_map(menu_map, sub_menu);

	return menu_map;
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
