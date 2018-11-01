#include "pch.h"
#include "ReturnAction.h"
#include <iostream>


ReturnAction::ReturnAction()
{
	std::cout << "Return action constructor.\n";

}


ReturnAction::~ReturnAction()
{
	std::cout << "Return action destructor.\n";

}

void ReturnAction::perform_action() const
{
	std::cout << "Returning to previous menu.\n";
}

