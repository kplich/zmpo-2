#include "pch.h"
#include "DummyAction2.h"
#include <iostream>


DummyAction2::DummyAction2()
{
}


DummyAction2::~DummyAction2()
{
}

void DummyAction2::perform_action() const
{
	std::cout << "Performing action number 2.\n";
}

