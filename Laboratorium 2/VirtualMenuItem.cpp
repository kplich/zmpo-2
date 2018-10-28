#include "pch.h"
#include "VirtualMenuItem.h"


VirtualMenuItem::VirtualMenuItem()
{
}

//TODO: member initializer list instead of usual constructor!
VirtualMenuItem::VirtualMenuItem(const std::string description, const std::string command) 
	: description(description), command(command)
{
}


VirtualMenuItem::~VirtualMenuItem()
{
	
}


std::string VirtualMenuItem::get_command() const
{
	return command;
}

std::string VirtualMenuItem::get_description() const
{
	return description;
}


