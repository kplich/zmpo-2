#include "pch.h"
#include <iostream>
#include <vector>
#include "VirtualMenuItem.h"
#include "utility.h"
#include "Menu.h"

int main()
{
	std::map<std::string, VirtualMenuItem*>* menu_map = get_map_of_menu_items();

	VirtualMenuItem* main_menu = new Menu(menu_map, "Runs main menu.", "main");

	main_menu->run();
}
