#pragma once

//TODO: is this class really necessary?
/**
 * A generic kind of interface for defining actions for commands.
 */
class VirtualAction
{
public:
	/**
	 * Default constructor, for subclasses to invoke.
	 */
	//TODO: like constructor in VirtualMenuItem - does this has to be here?
	VirtualAction();

	/**
	 * Virtual destructor, for subclasses to <b>implement</b>!
	 */
	virtual ~VirtualAction() = 0;

	/**
	 * Method running the contents of the command.
	 */
	//TODO: should this be void?
	virtual void run_action() const = 0;
};

