#include "pch.h"
#include "VirtualMenuItem.h"
#include "utility.h"

int main()
{
	VirtualMenuItem* main_menu = get_main_menu();

	main_menu->run();

	delete main_menu;
}
