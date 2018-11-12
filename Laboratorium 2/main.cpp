#include "pch.h"
#include "prepare_menu.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "action_implementations.h"
#include <iostream>

int main()
{
	std::vector<Table*> table_vector;

	Menu* main_menu = get_main_menu(&table_vector);
	main_menu->save_menu("saved.txt");

	std::cout << main_menu->to_string() << "\n";
	main_menu->run();
	delete main_menu;

	//TODO: proof that this thing still doesn't work!
	main_menu = Menu::open_menu("saved.txt");

	if (main_menu != nullptr) {
		std::cout << "zadzialalo! :D :D :D\n";
		main_menu->run();
	}
	else
	{
		std::cout << "nie zadzialalo :(\n";
	}

	delete main_menu;

	deallocate_tables(&table_vector);
}
