#pragma once
#include "AbstractMenuItem.h"
#include "AbstractAction.h"

class MenuCommand : public AbstractMenuItem
{
public:
	/**
	 * Parametrized constructor.
	 */
	MenuCommand(AbstractAction* action, std::string description, std::string command);

	/**
	 * Destructor.
	 */
	~MenuCommand();

	/**
	 * Performs action defined in the action object if it's well-defined.
	 */
	void run();

private:
	/**
	 * Pointer to an action object.
	 */
	AbstractAction* action;
};

