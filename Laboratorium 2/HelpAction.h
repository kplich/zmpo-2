#pragma once
#include "AbstractAction.h"
#include <map>
#include "AbstractMenuItem.h"

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

