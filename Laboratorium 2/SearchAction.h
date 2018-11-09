#pragma once
#include "AbstractAction.h"
#include "Menu.h"

/**
 * Action for searching the menu for items with a given command
 */
class SearchAction: public AbstractAction
{
public:
	SearchAction(Menu* root_menu);
	~SearchAction();

	void perform_action() const override;

private:
	Menu* root_menu;
	std::map<std::string, AbstractMenuItem*>* found_items;
};

