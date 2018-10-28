#pragma once
#include "VirtualAction.h"
class DummyAction1 : public VirtualAction
{
public:
	DummyAction1();
	virtual ~DummyAction1();

	void perform_action() const override;
};

