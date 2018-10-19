#pragma once
#include "VirtualMenuItem.h"
#include "VirtualAction.h"

class MenuCommand : public VirtualMenuItem
{
public:
	MenuCommand();
	~MenuCommand();

	void run() const;

private:
	//TODO: a reference is implicitly constant, so maybe it'd be better?
	const VirtualAction* action;
};

