#pragma once
#include "VirtualMenuItem.h"
#include "VirtualAction.h"

class MenuCommand : public VirtualMenuItem
{
public:
	/**
	 * Default constructor.
	 */
	//TODO this one doesn't seem to be useful; one parametrized by VirtualAction would make more sense
	MenuCommand();

	/**
	 * Destructor.
	 */
	//TODO: what should implement here???
	~MenuCommand();

	/**
	 * Performs action defined in the @code {action} object if it's well-defined.
	 */
	void run() const;

private:
	/**
	 * Pointer to an action object.
	 */
	//TODO: a reference is implicitly constant, so maybe it'd be better?
	const VirtualAction* action;
};

