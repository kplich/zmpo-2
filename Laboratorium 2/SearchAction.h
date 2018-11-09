#pragma once
#include "AbstractAction.h"
#include "Menu.h"

//TODO: is it actually acceptable to separately interpret 'search' and command to look for?

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
};

