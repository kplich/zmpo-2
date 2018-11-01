#include "pch.h"
#include "DefaultAction.h"
#include <iostream>

DefaultAction::DefaultAction()
{
}

DefaultAction::~DefaultAction()
{
}

void DefaultAction::perform_action() const
{
	std::cout << "Default action.\n";
}

