#pragma once
#include "VirtualMenuItem.h"
#include <vector>
#include <map>
#include "MenuCommand.h"

class Menu : public VirtualMenuItem
{
	public:

		/**
		 * Parametrized constructor based on a <b>map</b> of menu items
		 */
		Menu(std::map<std::string, VirtualMenuItem*>* item_map, std::string description, std::string name);

		/**
		 * Destructor.
		 */
		//TODO: what to implement here?
		~Menu();

		/**
		 * Allows for interaction with the menu.
		 */
		//TODO: don't we need a pointer to the vector to modify it???
		void run();

	private:
		/**
		 * Map of menu items and their commands - both submenus and commands.
		 */
		std::map<std::string, VirtualMenuItem*>* item_map;

		/**
		 * Prints all menu items and their commands
		 */
		void print_options();

		/**
		 *
		 */
		VirtualMenuItem* choose_option();

		//TODO: this feels like it should be constant,
		//but we want each object to keep a separate copy of a return command for itself
		MenuCommand* return_command;
};