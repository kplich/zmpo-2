#include "pch.h"
#include "VirtualMenuItem.h"


VirtualMenuItem::VirtualMenuItem()
{
}

std::string VirtualMenuItem::get_command() const
{
	return command;
}

std::string VirtualMenuItem::get_name() const
{
	return name;
}


