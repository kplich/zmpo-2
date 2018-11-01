#pragma once
#include "AbstractAction.h"
class DefaultAction: public AbstractAction
{
public:
	DefaultAction();
	virtual ~DefaultAction();

	void perform_action() const override;
};

