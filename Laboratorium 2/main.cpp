#include "pch.h"
#include "AbstractMenuItem.h"
#include "prepare_menu.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "action_implementations.h"

int main()
{
	std::vector<Table*> table_vector;

	AbstractMenuItem* main_menu = get_main_menu(&table_vector);

	main_menu->run();

	delete main_menu;
	deallocate_tables(&table_vector);
}
