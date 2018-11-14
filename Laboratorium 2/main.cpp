#include "pch.h"
#include <vector>
#include <iostream>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "Menu.h"
#include "vector_based_action_classes.h"

Menu* get_main_menu(std::vector<Table*>* table_vector);

AbstractMenuItem* get_editing_menu(std::vector<Table*>* table_vector, Menu* main_menu, std::string menu_path);

int main()
{
	Menu* a = new Menu("", "a", nullptr, "");

		Menu* b = new Menu("", "b", a, a->get_path());

			Menu* d = new Menu("", "d", b, b->get_path());
			Menu* e = new Menu("", "e", b, b->get_path());

		Menu* c = new Menu("", "c", a, a->get_path());

			Menu* f = new Menu("", "f", c, c->get_path());
			Menu* g = new Menu("", "g", c, c->get_path());

	b->add_item(d);
	b->add_item(e);

	c->add_item(f);
	c->add_item(g);

	a->add_item(b);
	a->add_item(c);

	a->print_by_breadth();
}

//all these allocations are deallocated in Menu and Command destructors
Menu* get_main_menu(std::vector<Table*>* table_vector)
{
	Menu* main_menu = new Menu("Open main menu", "main_menu", nullptr, "");

	AbstractMenuItem* add_table = new Command(add_table_description, add_table_command,	main_menu->get_path(), new AddTable(table_vector), add_table_help);
	AbstractMenuItem* print_one = new Command(print_one_description, print_one_command, main_menu->get_path(), new PrintOneTable(table_vector), print_one_help);
	AbstractMenuItem* print_all = new Command(print_all_description, print_all_command, main_menu->get_path(), new PrintAllTables(table_vector), print_all_help);
	AbstractMenuItem* clone_table = new Command(clone_table_description, clone_table_command, main_menu->get_path(), new CloneTable(table_vector), clone_table_help);
	AbstractMenuItem* delete_one_table = new Command(delete_one_description, delete_one_command, main_menu->get_path(), new DeleteOneTable(table_vector), delete_one_help);
	AbstractMenuItem* delete_all_tables = new Command(delete_all_description, delete_all_command, main_menu->get_path(),  new DeleteAllTables(table_vector), delete_all_help);
	AbstractMenuItem* edit_table = get_editing_menu(table_vector, main_menu, main_menu->get_path());

	main_menu->add_item(add_table);
	main_menu->add_item(print_one);
	main_menu->add_item(print_all);
	main_menu->add_item(clone_table);
	main_menu->add_item(delete_one_table);
	main_menu->add_item(delete_all_tables);
	main_menu->add_item(edit_table);

	return main_menu;
}

AbstractMenuItem* get_editing_menu(std::vector<Table*>* table_vector, Menu* main_menu, std::string menu_path)
{
	Menu* editing_menu = new Menu("Edit table", "edit", main_menu, menu_path);

	AbstractMenuItem* rename_table = new Command(rename_table_description, rename_table_command, editing_menu->get_path(), new RenameTable(table_vector), rename_table_help);
	AbstractMenuItem* resize_table = new Command(resize_table_description, resize_table_command, editing_menu->get_path(), new ResizeTable(table_vector), resize_table_help);
	AbstractMenuItem* put_value = new Command(put_value_description, put_value_command, editing_menu->get_path(), new PutValue(table_vector), put_value_help);

	editing_menu->add_item(rename_table);
	editing_menu->add_item(resize_table);
	editing_menu->add_item(put_value);

	return editing_menu;
}
