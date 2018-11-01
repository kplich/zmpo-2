#pragma once
#include "AbstractAction.h"

class ReturnAction:
	public AbstractAction
{
public:
	ReturnAction();
	~ReturnAction();
	void perform_action() const override;
};

