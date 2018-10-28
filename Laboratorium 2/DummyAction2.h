#pragma once
#include "VirtualAction.h"
class DummyAction2 :
	public VirtualAction
{
public:
	DummyAction2();
	virtual ~DummyAction2();

	void perform_action() const override;
};

