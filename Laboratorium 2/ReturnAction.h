#pragma once
#include "VirtualAction.h"
class ReturnAction:
	public VirtualAction
{
	public:
		ReturnAction();
		~ReturnAction();
		void perform_action() const;
};

