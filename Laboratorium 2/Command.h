#pragma once
#include "AbstractMenuItem.h"
#include "AbstractAction.h"

class Menu;
class ParsingStack;

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

	std::string to_string() override;

	static Command* parse_command(ParsingStack* input, std::string parent_path);

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

