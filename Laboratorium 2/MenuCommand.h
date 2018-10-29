#pragma once
#include "VirtualMenuItem.h"
#include "VirtualAction.h"

class MenuCommand : public VirtualMenuItem
{
public:
	/**
	 * Parametrized constructor.
	 */
	MenuCommand(VirtualAction* action, std::string description, std::string command);

	/**
	 * Destructor.
	 */
	//TODO: what should implement here???
	~MenuCommand();

	/**
	 * Performs action defined in the action object if it's well-defined.
	 */
	void run();

private:
	/**
	 * Pointer to an action object.
	 */
	//TODO: a reference is implicitly constant, so maybe it'd be better?
	const VirtualAction* action;
};

