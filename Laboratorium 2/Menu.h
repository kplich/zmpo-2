#pragma once
#include "VirtualMenuItem.h"
#include <vector>

class Menu : public VirtualMenuItem
{
public:
	//TODO construction based on a vector of menu items

	/**
	 * Default constructor.
	 */
	//TODO is it useful?
	Menu();

	/**
	 * Constructor based on a vector of menu items
	 */
	Menu(std::vector<VirtualMenuItem*> menu_items);

	/**
	 * Destructor.
	 */
	//TODO: what to implement here?
	~Menu();

	/**
	 * Allows for interaction with the menu.
	 */
	void run() const;

private:
	/**
	 * List of menu items - both submenus and commands.
	 */
	//TODO: maybe a map for command names and menu items would be safer?
	std::vector<VirtualMenuItem*> menu_items;
};

