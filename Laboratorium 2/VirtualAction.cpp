#include "pch.h"
#include "VirtualAction.h"
#include <iostream>


VirtualAction::VirtualAction()
{
	std::cout << "Virtual action constructor.\n";
}

VirtualAction::~VirtualAction()
{
	std::cout << "Virtual action destructor.\n";
}
//TODO: should a destructor be here?
