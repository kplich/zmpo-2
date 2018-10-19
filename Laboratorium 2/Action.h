#pragma once
#include "VirtualAction.h"

/**
 * Some action that can be performed in a menu.
 */
//TODO: does every action need a separate class???
class Action : public VirtualAction
{
public:
	Action();
	~Action();
};

