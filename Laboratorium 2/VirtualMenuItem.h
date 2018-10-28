#pragma once
#include <string>

/**
 * Generic class for implementing a runnable menu item.
 * <b>Not mutable!</b>
 */
//TODO: is it exactly 'pure virtual'?
class VirtualMenuItem
{
public:
	/**
	 * Default constructor, declared for subclasses to invoke.
	 */
	//TODO: either delete it or make protected?
	VirtualMenuItem();

	//TODO: shouldn't it actually be virtual???
	/**
	 * Destructor. Must be implemented by subclasses.
	 */
	~VirtualMenuItem();

	/**
	 * Virtual method that performs some action.
	 */
	//TODO: should this really return void?
	virtual void run() const = 0;

	/**
	 * Returns the command used to run the item.
	 * @return command used to run the item
	 */
	//TODO: does this has to be here, has to be virtual or maybe not?
	std::string get_command() const;

	/**
	 * Returns name of the item.
	 * @return string containing short name of the item
	 */
	//TODO: as mentioned earlier
	std::string get_name() const;

private:
	/**
	 * Command that will be used to perform an action.
	 */
	const std::string command;

	/**
	 * Name of the menu or action performed.
	 */
	const std::string name;
};

