#pragma once
#include "VirtualAction.h"
class DefaultAction:
	public VirtualAction
{
public:
	DefaultAction();
	virtual ~DefaultAction();

	void perform_action() const override;
};

