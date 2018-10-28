#include "pch.h"
#include "ReturnAction.h"
#include <iostream>


ReturnAction::ReturnAction()
{
}


ReturnAction::~ReturnAction()
{
}

void ReturnAction::perform_action() const
{
	std::cout << "Returning to previous menu.\n";
}

