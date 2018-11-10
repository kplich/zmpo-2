#pragma once
#include "AbstractMenuItem.h"
#include "AbstractAction.h"

class Command : public AbstractMenuItem
{
public:
	/**
	 * Parametrized constructor.
	 */
	Command(std::string description, std::string command, std::string parent_path,
		    AbstractAction* action, std::string help);

	/**
	 * Destructor.
	 */
	~Command();

	/**
	 * Performs action defined in the action object if it's well-defined.
	 */
	void run() override;

	/**
	 * Returns string containing help for a given command.
	 */
	std::string get_help();

private:
	/**
	 * Pointer to an action object.
	 */
	AbstractAction* action;

	/**
	 * Additional information about the command.
	 */
	std::string help;
};

