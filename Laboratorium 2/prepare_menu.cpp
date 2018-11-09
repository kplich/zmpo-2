#include "pch.h"
#include "prepare_menu.h"
#include "Menu.h"
#include <iostream>
#include "vector_based_action_classes.h"

//all these allocations are deallocated in Menu and Command destructors
//TODO: not nice menu building
AbstractMenuItem* get_main_menu(std::vector<Table*>* table_vector)
{
	//TODO: ugly nullptr here
	Menu* main_menu = new Menu("Open main menu", "main_menu", nullptr, "main menu");

	AbstractMenuItem* add_table = new Command(
		new AddTable(table_vector),
		"Add a new table",
		"add",
		main_menu->get_path()
	);

	AbstractMenuItem* print_one = new Command(
		new PrintOneTable(table_vector),
		"Print one of the tables",
		"print one",
		main_menu->get_path()
	);

	AbstractMenuItem* print_all = new Command(
		new PrintAllTables(table_vector),
		"Print all tables",
		"print all",
		main_menu->get_path()
	);

	AbstractMenuItem* edit_table = get_editing_menu(table_vector, main_menu, main_menu->get_path());

	AbstractMenuItem* clone_table = new Command(
		new CloneTable(table_vector),
		"Clone chosen table",
		"clone",
		main_menu->get_path()
	);

	AbstractMenuItem* delete_one_table = new Command(
		new DeleteOneTable(table_vector),
		"Delete single, chosen table",
		"delete one",
		main_menu->get_path()
	);

	AbstractMenuItem* delete_all_tables = new Command(
		new DeleteAllTables(table_vector),
		"Delete all tables",
		"delete all",
		main_menu->get_path()
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
		new RenameTable(table_vector),
		"Rename chosen table",
		"rename",
		editing_menu->get_path()
	);

	AbstractMenuItem* resize_table = new Command(
		new ResizeTable(table_vector),
		"Resize chosen table",
		"resize",
		editing_menu->get_path()
	);

	AbstractMenuItem* put_value = new Command(
		new PutValue(table_vector),
		"Put value into the chosen table",
		"put value",
		editing_menu->get_path()
	);

	editing_menu->add_item(rename_table);
	editing_menu->add_item(resize_table);
	editing_menu->add_item(put_value);

	return editing_menu;
}

