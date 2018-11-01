#include "pch.h"
#include "prepare_menu.h"
#include "Menu.h"
#include <iostream>
#include "vector_based_action_classes.h"

//all these allocations are deallocated in Menu and MenuCommand destructors

AbstractMenuItem* get_main_menu(std::vector<Table*>* table_vector)
{
	Menu* main_menu = new Menu("Open main menu", "main_menu");

	AbstractMenuItem* add_table = new MenuCommand(
		new AddTable(table_vector),
		"Add a new table",
		"add"
	);

	AbstractMenuItem* print_one = new MenuCommand(
		new PrintOneTable(table_vector),
		"Print one of the tables",
		"print one"
	);

	AbstractMenuItem* print_all = new MenuCommand(
		new PrintAllTables(table_vector),
		"Print all tables",
		"print all"
	);

	AbstractMenuItem* edit_table = get_editing_menu(table_vector);

	AbstractMenuItem* clone_table = new MenuCommand(
		new CloneTable(table_vector),
		"Clone chosen table",
		"clone"
	);

	AbstractMenuItem* delete_one_table = new MenuCommand(
		new DeleteOneTable(table_vector),
		"Delete single, chosen table",
		"delete one"
	);

	AbstractMenuItem* delete_all_tables = new MenuCommand(
		new DeleteAllTables(table_vector),
		"Delete all tables",
		"delete all"
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

AbstractMenuItem* get_editing_menu(std::vector<Table*>* table_vector)
{
	Menu* editing_menu = new Menu("Edit table", "edit");

	AbstractMenuItem* rename_table = new MenuCommand(
		new RenameTable(table_vector),
		"Rename chosen table",
		"rename"
	);

	AbstractMenuItem* resize_table = new MenuCommand(
		new ResizeTable(table_vector),
		"Resize chosen table",
		"resize"
	);

	AbstractMenuItem* put_value = new MenuCommand(
		new PutValue(table_vector),
		"Put value into the chosen table",
		"put value"
	);

	editing_menu->add_item(rename_table);
	editing_menu->add_item(resize_table);
	editing_menu->add_item(put_value);

	return editing_menu;
}

