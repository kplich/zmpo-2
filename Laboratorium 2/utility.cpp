#include "pch.h"
#include "utility.h"
#include "VirtualAction.h"
#include "DummyAction2.h"
#include "Menu.h"
#include "DummyAction1.h"
#include "MenuCommand.h"
#include <iostream>

std::vector<VirtualMenuItem*>* get_menu_items()
{
	VirtualAction* sub_action_1 = new DummyAction1();
	VirtualAction* sub_action_2 = new DummyAction2();

	VirtualMenuItem* command_1 = new MenuCommand(sub_action_1, "Perform action 1", "action_1");
	VirtualMenuItem* command_2 = new MenuCommand(sub_action_2, "Perform action 2", "action_2");

	std::vector<VirtualMenuItem*>* sub_menu_vector = new std::vector<VirtualMenuItem*>();

	sub_menu_vector->push_back(command_1);
	sub_menu_vector->push_back(command_2);

	VirtualMenuItem* sub_menu = new Menu(sub_menu_vector, "Open sub-menu", "sub_menu");

	std::vector<VirtualMenuItem*>* menu = new std::vector<VirtualMenuItem*>();

	menu->push_back(command_1);
	menu->push_back(command_2);
	menu->push_back(sub_menu);

	//TODO: implement this
	return menu;
}

std::map<std::string, VirtualMenuItem*>* get_map_of_menu_items()
{
	VirtualAction* sub_action_1 = new DummyAction1();
	VirtualAction* sub_action_2 = new DummyAction2();


	return nullptr;
}

std::string get_input_from_user()
{
	std::string result;
	std::getline(std::cin, result);
	return result;
}
