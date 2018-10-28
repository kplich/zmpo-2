#include "pch.h"
#include "menu_items.h"


Menu::Menu()
{
}

Menu::Menu(std::vector<VirtualMenuItem*> menu_items)
{
	this->menu_items = menu_items;
}


Menu::~Menu()
{
}

void Menu::run() const
{
	
}
