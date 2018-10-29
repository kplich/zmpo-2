#include "pch.h"
#include "action_implementations.h"
#include <iostream>
#include "../../Laboratorium 1/Laboratorium 1/editing_menu.h"
#include "input_output.h"

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
		Table* edited_table = get_table_for_editing(*tables);

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
//--------------------------------------------------------------------------------------

Table* get_table_for_editing(std::vector<Table*>* tables)
{
	std::cout << "Ktora tabele chcesz edytowac?\n";

	int chosen_index = loop_until_valid_int(0, tables->size() - 1);

	return tables->at(chosen_index);
}

void rename_table(Table* edited_table)
{
	std::cout << "Podaj nowa nazwe tabeli.\n";
	std::cout << "Obecna nazwa tabeli: " << edited_table->get_table_name() << "\n";
	std::string new_name = get_user_input();

	edited_table->set_table_name(new_name);
}

void resize_table(Table* edited_table)
{
	std::cout << "Podaj nowy rozmiar tabeli.\n";
	std::cout << "Obecny rozmiar tabeli: " << edited_table->get_table_length() << "\n";
	std::cout << "Uwaga! Podanie rozmiaru mniejszego niz obecny spowoduje utrate danych!\n";

	int new_size = loop_until_valid_int(1, MAX_TABLE_SIZE);

	bool resize_successful = edited_table->set_table_length(new_size);

	communicate_success(resize_successful);
}

void put_value(Table* edited_table)
{
	std::cout << "Podaj wartosc, ktora chcesz wpisac do tabeli.\n";

	int new_value = loop_until_valid_int(MIN_INTEGER, MAX_INTEGER);

	std::cout << "Na ktorej pozycji chcesz wpisac nowa wartosc?\n";

	int chosen_index = loop_until_valid_int(0, edited_table->get_table_length() - 1);

	bool write_successful = edited_table->set_value(chosen_index, new_value);

	communicate_success(write_successful);
}