#pragma once
#include "VirtualMenuItem.h"
#include <vector>
#include <map>
#include "MenuCommand.h"

class Menu : public VirtualMenuItem
{
	public:
		/**
		 * Constructor not based on a map - menus can be expanded during runtime
		 */
		Menu(std::string description, std::string command);

		/**
		 * Parametrized constructor based on a <b>map</b> of menu items
		 */
		Menu(std::map<std::string, VirtualMenuItem*>* item_map, std::string description, std::string command);

		/**
		 * Destructor.
		 */
		//TODO: what to implement here?
		~Menu();

		/**
		 * Allows for interaction with the menu.
		 */
		void run() override;

		void add_new_item(VirtualMenuItem* new_item);

	private:
		/**
		 * Map of menu items and their commands - both submenus and commands.
		 */
		std::map<std::string, VirtualMenuItem*>* item_map{};

		/**
		 * Prints all menu items and their commands
		 */
		void print_options();

		/**
		 * Method for choosing a command or submenu.
		 * @return pointer to chosen menu item
		 */
		VirtualMenuItem* choose_option();

		//TODO: this feels like it should be constant,
		//but we want each object to keep a separate copy of a return command for itself
		MenuCommand* return_command;

		/**
		 * Helper method to simplify inserting VirtualMenuItems into a map
		 * @param item_map map of items into which we insert the new item
		 * @param menu_item item that we're inserting
		 */
		void insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item);
};