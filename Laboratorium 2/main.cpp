#include "pch.h"
#include "VirtualMenuItem.h"
#include "utility.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

int main()
{
	std::vector<Table*> table_vector;

	VirtualMenuItem* main_menu = get_main_menu(&table_vector);

	main_menu->run();

	delete main_menu;
}
