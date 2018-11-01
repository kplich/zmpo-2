#pragma once
#include <string>

/**
 * Generic class for implementing a runnable menu item.
 * <b>Not mutable!</b>
 */
class AbstractMenuItem
{
public:
	AbstractMenuItem(const std::string description, const std::string command);

	/**
	 * Virtual destructor.
	 */
	virtual ~AbstractMenuItem();

	/**
	 * Virtual method that runs the menu or performs an action.
	 */
	//Pure virtual method makes the class abstract.
	virtual void run() = 0;

	/**
	 * Returns the command used to run the item.
	 * @return command used to run the item
	 */
	std::string get_command() const;

	/**
	 * Returns description of the item.
	 * @return string containing short description of the item
	 */
	std::string get_description() const;

protected:
	/**
	 * Description of the menu or action performed.
	 */
	const std::string description;

	/**
	 * Command that will be used to perform an action.
	 */
	const std::string command;
};

