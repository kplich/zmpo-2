#include "pch.h"
#include "DummyAction1.h"
#include <iostream>


DummyAction1::DummyAction1()
{
}


DummyAction1::~DummyAction1()
{
}

void DummyAction1::perform_action() const
{
	std::cout << "Performing action number 1\n";
}

