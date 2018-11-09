#pragma once
#include "AbstractMenuItem.h"
#include <vector>
#include <map>
#include "Command.h"

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
	 * Method for searching for a menu item in the whole subtree (invoked recursively)
	 * @command_name name of the command to find
	 */
	std::map<std::string, AbstractMenuItem*> search_for_command(std::string command_name);

	/**
	 * Helper method to simplify inserting VirtualMenuItems into a map
	 * @param item_map map of items into which we insert the new item
	 * @param menu_item item that we're inserting
	 */
	void insert_item_into_map(std::map<std::string, AbstractMenuItem*>* item_map, AbstractMenuItem* menu_item);

	/**
	 * Command object that makes the user leave the current menu.
	 * It's kept as a part of a menu for later comparison.
	 */
	Command* return_command_object;

	/**
	 * Command object that allows for searching the menu.
	 */
	Command* search_command_object;
};
