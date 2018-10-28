#pragma once
#include "VirtualMenuItem.h"
#include <vector>
#include <map>

class Menu : public VirtualMenuItem
{
public:
	//TODO construction based on a vector of menu items

	/**
	 * Default constructor.
	 */
	//TODO is it useful?
	Menu();

	//TODO: delete one of these constructors
	/**
	 * Constructor based on a vector of menu items
	 */
	Menu(std::vector<VirtualMenuItem*>* menu_items, std::string description, std::string name);

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
	 * List of menu items - both submenus and commands.
	 */
	//TODO: maybe a map for command names and menu items would be safer?
	std::vector<VirtualMenuItem*>* menu_items;

	std::map<std::string, VirtualMenuItem*>* item_map;

	void print_options();

	VirtualMenuItem* choose_option();
};

