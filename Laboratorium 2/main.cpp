#include "pch.h"
#include <iostream>
#include <vector>
#include "VirtualMenuItem.h"
#include "utility.h"
#include "Menu.h"

int main()
{
	std::vector<VirtualMenuItem*>* menu_items = get_menu_items();
	VirtualMenuItem* main_menu = new Menu(menu_items, "Runs main menu.", "main");

	main_menu->run();
}
