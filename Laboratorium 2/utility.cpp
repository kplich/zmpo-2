#include "pch.h"
#include "utility.h"
#include "VirtualAction.h"
#include "DummyAction2.h"
#include "Menu.h"
#include "DummyAction1.h"
#include "MenuCommand.h"

std::vector<VirtualMenuItem*>* get_menu_items()
{
	VirtualAction* sub_action_1 = new DummyAction1();
	VirtualAction* sub_action_2 = new DummyAction2();

	VirtualMenuItem* command_1 = new MenuCommand(sub_action_1);
	VirtualMenuItem* command_2 = new MenuCommand(sub_action_2);

	std::vector<VirtualMenuItem*> sub_menu_vector;

	sub_menu_vector.push_back(command_1);
	sub_menu_vector.push_back(command_2);

	VirtualMenuItem* sub_menu = new Menu(&sub_menu_vector);

	std::vector<VirtualMenuItem*> menu;

	menu.push_back(command_1);
	menu.push_back(command_2);
	menu.push_back(sub_menu);

	//TODO: implement this
	return &menu;
}

std::map<std::string, VirtualMenuItem*>* get_map_of_menu_items()
{
	return nullptr;
}
