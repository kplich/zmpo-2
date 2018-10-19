#pragma once

//TODO: is this class really necessary?
/**
 * 
 */
class VirtualCommand
{
public:
	/**
	 * Default constructor, for subclasses to invoke.
	 */
	//TODO: like constructor in VirtualMenuItem - does this has to be here?
	VirtualCommand();

	/**
	 * Virtual destructor, for subclasses to <b>implement</b>!
	 */
	virtual ~VirtualCommand() = 0;

	/**
	 * Method running the contents of the command.
	 */
	//TODO: should this be void?
	virtual void run_command() = 0;
};

