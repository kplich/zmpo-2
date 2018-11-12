#include "pch.h"
#include "prepare_menu.h"
#include "Menu.h"
#include <iostream>
#include "vector_based_action_classes.h"

//TODO: extract strings
const std::string add_table_help = "Here you can create a new table, set its name and length.";
const std::string print_one_help = "Print contents of the chosen table.";
const std::string print_all_help = "Print information about all added tables.";
const std::string clone_table_help = "Add a copy of a chosen table to the collection.";
const std::string delete_one_help = "Delete chosen table from the collection.";
const std::string delete_all_help = "Delete ALL tables from the collection.";
const std::string rename_table_help = "Change the name of a chosen table.";
const std::string resize_table_help = "Change the size of a chosen table.\nIf you shrink the table, your information may be lost.";
const std::string put_value_help = "Change a desired value in one of the chosen tables.";

//all these allocations are deallocated in Menu and Command destructors
//TODO: not nice menu building
Menu* get_main_menu(std::vector<Table*>* table_vector)
{
	//TODO: ugly nullptr here
	Menu* main_menu = new Menu("Open main menu", "main_menu", nullptr, "");

	AbstractMenuItem* add_table = new Command(
		"Add a new table",
		"add",
		main_menu->get_path(),
		new AddTable(table_vector),
		add_table_help
	);

	AbstractMenuItem* print_one = new Command(
		"Print one of the tables",
		"print one",
		main_menu->get_path(),
		new PrintOneTable(table_vector),
		print_one_help
	);

	AbstractMenuItem* print_all = new Command(
		"Print all tables",
		"print all",
		main_menu->get_path(),
		new PrintAllTables(table_vector),
		print_all_help
	);

	AbstractMenuItem* edit_table = get_editing_menu(table_vector, main_menu, main_menu->get_path());

	AbstractMenuItem* clone_table = new Command(
		"Clone chosen table",
		"clone",
		main_menu->get_path(),
		new CloneTable(table_vector),
		clone_table_help
	);

	AbstractMenuItem* delete_one_table = new Command(
		"Delete single, chosen table",
		"delete one",
		main_menu->get_path(),
		new DeleteOneTable(table_vector),
		delete_one_help
	);

	AbstractMenuItem* delete_all_tables = new Command(
		"Delete all tables",
		"delete all",
		main_menu->get_path(),
		new DeleteAllTables(table_vector),
		delete_all_help
	);

	main_menu->add_item(add_table);
	main_menu->add_item(print_one);
	main_menu->add_item(print_all);
	main_menu->add_item(edit_table);
	main_menu->add_item(clone_table);
	main_menu->add_item(delete_one_table);
	main_menu->add_item(delete_all_tables);

	return main_menu;
}

AbstractMenuItem* get_editing_menu(std::vector<Table*>* table_vector, Menu* main_menu, std::string menu_path)
{
	Menu* editing_menu = new Menu("Edit table", "edit", main_menu, menu_path);

	AbstractMenuItem* rename_table = new Command(
		"Rename chosen table",
		"rename",
		editing_menu->get_path(),
		new RenameTable(table_vector),
		rename_table_help
	);

	AbstractMenuItem* resize_table = new Command(
		"Resize chosen table",
		"resize",
		editing_menu->get_path(),
		new ResizeTable(table_vector),
		resize_table_help
	);

	AbstractMenuItem* put_value = new Command(
		"Put value into the chosen table",
		"put value",
		editing_menu->get_path(),
		new PutValue(table_vector),
		put_value_help
	);

	editing_menu->add_item(rename_table);
	editing_menu->add_item(resize_table);
	editing_menu->add_item(put_value);

	return editing_menu;
}

