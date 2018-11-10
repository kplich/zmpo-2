#pragma once
#include "AbstractMenuItem.h"
#include "AbstractAction.h"

class Command : public AbstractMenuItem
{
public:
	/**
	 * Parametrized constructor.
	 */
	Command(AbstractAction* action, std::string description, std::string command, std::string parent_path);

	/**
	 * Destructor.
	 */
	~Command();

	/**
	 * Performs action defined in the action object if it's well-defined.
	 */
	void run() override;

	std::string get_help();

private:
	/**
	 * Pointer to an action object.
	 */
	AbstractAction* action;

	std::string help;
};

