#include "pch.h"
#include "AbstractAction.h"
#include <iostream>


AbstractAction::AbstractAction()
{
	std::cout << "Virtual action constructor.\n";
}

AbstractAction::~AbstractAction()
{
	std::cout << "Virtual action destructor.\n";
}
