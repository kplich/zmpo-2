#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}

Menu::Menu(std::vector<VirtualMenuItem*>* menu_items)
{
	this->menu_items = menu_items;
}


Menu::~Menu()
{
}

void Menu::run() const
{
	
}
