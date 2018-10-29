#include "pch.h"
#include "action_implementations.h"
#include "../../Laboratorium 1/Laboratorium 1/io_utility.h"
#include <iostream>
#include "../../Laboratorium 1/Laboratorium 1/editing_menu.h"

void print_all_tables(std::vector<Table*>* tables)
{
	std::cout << "Wszystkie tablice:\n";

	for (int i = 0; i < tables->size(); ++i)
	{
		std::cout << "index " << i << "\t" << tables->at(i)->to_short_string() << std::endl;
	}
}

void print_one_table(std::vector<Table*>* tables)
{
	std::cout << "Któr¹ tabelê chcesz wyœwietliæ? (indeksy zaczynaj¹ siê od zera)\n";

	int chosen_table_number = loop_until_valid_int(0, tables->size() - 1);

	//write out the table
	std::cout << "Tablica nr: " << chosen_table_number << ":" << "\n";
	std::cout << tables->at(chosen_table_number)->to_full_string();
}

void add_table(std::vector<Table*>* tables)
{
	Table* new_table;

	std::cout << "Podaj nazwê nowej tablicy (wpisz default, aby stworzyæ domyœln¹ tablicê):\n";
	std::string name = get_user_input();

	if (name == "default")
	{
		new_table = new Table();
		tables->push_back(new_table);
		return;
	}
	else
	{
		std::cout << "Podaj rozmiar nowej tablicy:\n";

		int size = loop_until_valid_int(0, MAX_TABLE_SIZE);

		new_table = new Table(name, size);
	}

	tables->push_back(new_table);
}

void edit_table(std::vector<Table*>* tables)
{
	if (tables->empty())
	{
		std::cout << "Nie dodano zadnej tablicy.\n";
	}
	else
	{
		Table* edited_table = get_table_for_editing(tables);

		run_editing_loop(edited_table);
	}
}

void clone_table(std::vector<Table*>* tables)
{
	if (tables->empty())
	{
		std::cout << "Nie dodano zadnej tablicy.\n";
	}
	else
	{
		std::cout << "Ktora tabele chcesz sklonowac? (indeksy zaczynaj¹ siê od zera)\n";

		int chosen_table_number = loop_until_valid_int(0, tables->size() - 1);

		Table* cloned_table = new Table(*tables->at(chosen_table_number));
		tables->push_back(cloned_table);
	}
}

void delete_all_tables(std::vector<Table*>* tables)
{
	std::cout << "Czy jesteœ pewien, ¿e chcesz usun¹æ wszystkie tablice?" << std::endl;
	std::cout << "Wpisz 1, aby potwierdziæ." << std::endl;

	int confirmation = 1;

	get_int_input(confirmation, 0, 1);

	if (confirmation == 1)
	{
		deallocate_tables(tables);
	}
}

void delete_one_table(std::vector<Table*>* tables)
{
	if (tables->empty())
	{
		std::cout << "Nie dodano zadnej tablicy.\n";
	}
	else
	{
		std::cout << "Któr¹ tabelê chcesz usun¹æ? (indeksy zaczynaj¹ siê od zera)\n";

		int chosen_table_number = loop_until_valid_int(0, tables->size() - 1);

		//deallocate the table's memory
		delete tables->at(chosen_table_number);

		//delete the pointer from the vector
		tables->erase(tables->begin() + chosen_table_number);
	}
}

void deallocate_tables(std::vector<Table*>* tables)
{
	while (tables->size() > 0)
	{
		Table* table = tables->at(0);

		delete table;

		tables->erase(tables->begin());
	}
}