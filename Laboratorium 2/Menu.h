#pragma once
#include "AbstractMenuItem.h"
#include <vector>
#include <map>
#include "Command.h"
#include "../ParsingStack/ParsingStack.h"

class Menu : public AbstractMenuItem
{
public:
	/**
	 * Constructor not based on a map - menus can be expanded during runtime
	 */
	Menu(std::string description, std::string command, Menu* root_menu, std::string parent_path);

	/**
	 * Parametrized constructor based on a <b>map</b> of menu items
	 */
	Menu(std::map<std::string, AbstractMenuItem*>* item_map, std::string description, std::string command, Menu* root_menu, std::string parent_path);

	/**
	 * All resources are released here - each menu item, including the return item, and the map itself.
	 */
	~Menu();

	/**
	 * Allows for interaction with the menu.
	 */
	void run() override;

	/**
	 * Allows for adding a new menu item.
	 * @param new_item pointer to new item to be added
	 */
	void add_item(AbstractMenuItem* new_item);

	/**
	 * Allows for deleting an item from the menu.
	 * @param item_command command used to invoke the item
	 */
	void delete_item(std::string item_command);

	/**
	 * Method for searching for a menu item in the whole subtree (invoked recursively)
	 * @param command_name name of the command to find
	 * @param found_paths map for storing items found so far and adding new ones
	 */
	//TODO: should this really be public?
	void search_for_command(std::string command_name, std::vector<std::string>* found_paths);

	/**
	 * Returns a textual representation of the string.
	 * @return a string in the format ("description","command";<child1>,<child2>,...)
	 */
	std::string to_string() override;

	/**
	 * Saves the menu to a text file.
	 */
	 //TODO: not entirely sure about this signature.
	void save_menu();

private:

	/**
	 * Map of menu items and their commands - both submenus and commands.
	 */
	std::map<std::string, AbstractMenuItem*>* item_map;

	/**
	 * Pointer to the root menu.
	 */
	Menu* root_menu;

	/**
	 * Prints all menu items and their commands
	 */
	void print_options();

	/**
	 * Method for choosing a command or submenu.
	 * @return pointer to chosen menu item
	 */
	AbstractMenuItem* choose_option();

	/**
	 * Helper method to simplify inserting VirtualMenuItems into a map
	 * @param found_items map of items into which we insert the new item
	 * @param menu_item item that we're inserting
	 */
	void insert_item_into_map(std::map<std::string, AbstractMenuItem*>* found_items, AbstractMenuItem* menu_item);

	static Menu* parse_menu(ParsingStack* input, Menu* root_menu, std::string parent_path);

	/**
	 * Command object that makes the user leave the current menu.
	 */
	Command* return_item;

	/**
	 * Command object that allows for searching the menu.
	 */
	Command* search_item;

	/**
	 * Command object that allows for getting help about a command within current menu.
	 */
	Command* help_item;
};
