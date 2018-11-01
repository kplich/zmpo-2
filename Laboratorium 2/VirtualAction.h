#pragma once

//TODO: is this class really necessary?
/**
 * Generic interface for defining actions for commands.
 */
class VirtualAction
{
public:
	/**
	 * Default constructor, for subclasses to invoke.
	 */
	//TODO: like constructor in AbstractMenuItem - does this has to be here?
	VirtualAction();

	/**
	 * Virtual destructor.
	 */
	virtual ~VirtualAction();

	/**
	 * Method running the contents of the command.
	 */
	//TODO: should this be void?
	virtual void perform_action() const = 0;
};

