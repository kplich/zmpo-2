#include "pch.h"
#include "VirtualMenuItem.h"
#include <iostream>


VirtualMenuItem::VirtualMenuItem()
{
}

//TODO: member initializer list instead of usual constructor!
VirtualMenuItem::VirtualMenuItem(const std::string description, const std::string command) 
	: description(description), command(command)
{
	std::cout << "Parametrized VirtualMenuItem constructor, " << command << "\n";
}


VirtualMenuItem::~VirtualMenuItem()
{
	std::cout << "VirtualMenuItem destructor, " << command << "\n";
}


std::string VirtualMenuItem::get_command() const
{
	return command;
}

std::string VirtualMenuItem::get_description() const
{
	return description;
}


