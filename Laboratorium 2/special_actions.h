#pragma once
#include "AbstractAction.h"
#include <map>
#include "AbstractMenuItem.h"
#include "Menu.h"

class DefaultAction : public AbstractAction
{
public:
	DefaultAction();
	virtual ~DefaultAction();

	void perform_action() const override;
};

/**
 * Action for searching for help in a menu.
 */
class HelpAction :
	public AbstractAction
{
public:
	HelpAction(std::map<std::string, AbstractMenuItem*>* item_map);
	~HelpAction();
	void perform_action() const override;
private:
	std::map<std::string, AbstractMenuItem*>* item_map;
};

class ReturnAction :
	public AbstractAction
{
public:
	ReturnAction();
	~ReturnAction();
	void perform_action() const override;
};

/**
 * Action for searching the menu for items with a given command
 */
class SearchAction : public AbstractAction
{
public:
	SearchAction(Menu* root_menu);
	~SearchAction();

	void perform_action() const override;

private:
	Menu* root_menu;
};