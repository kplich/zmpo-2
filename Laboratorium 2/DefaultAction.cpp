#include "pch.h"
#include "DefaultAction.h"
#include <iostream>

DefaultAction::DefaultAction()
{
	std::cout << "Default action constructor.\n";
}

DefaultAction::~DefaultAction()
{
	std::cout << "Default action destructor.\n";
}

void DefaultAction::perform_action() const
{
	std::cout << "Default action.\n";
}

