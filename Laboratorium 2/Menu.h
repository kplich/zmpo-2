#pragma once
#include "AbstractMenuItem.h"
#include <vector>
#include <map>
#include "MenuCommand.h"

class Menu : public AbstractMenuItem
{
public:
	/**
	 * Constructor not based on a map - menus can be expanded during runtime
	 */
	Menu(std::string description, std::string command);

	/**
	 * Parametrized constructor based on a <b>map</b> of menu items
	 */
	Menu(std::map<std::string, AbstractMenuItem*>* item_map, std::string description, std::string command);

	//TODO: what to implement here?
	~Menu();

	/**
	 * Allows for interaction with the menu.
	 */
	void run() override;

	/**
	 * Allows for adding a new menu item.
	 * @param new_item pointer to new item to be added
	 */
	void add_new_item(AbstractMenuItem* new_item);

	void delete_item(std::string item_command);

private:

	/**
	 * Map of menu items and their commands - both submenus and commands.
	 */
	std::map<std::string, AbstractMenuItem*>* item_map;

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
	 * @param item_map map of items into which we insert the new item
	 * @param menu_item item that we're inserting
	 */
	void insert_item_into_map(std::map<std::string, AbstractMenuItem*>* item_map, AbstractMenuItem* menu_item);

	/**
	 * Command object that makes the user leave the current menu.
	 * It's kept as a part of a menu for later comparison.
	 */
	MenuCommand* return_command_object;
};