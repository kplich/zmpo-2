#include "pch.h"
#include "AbstractMenuItem.h"

//member initializer list instead of usual constructor!
AbstractMenuItem::AbstractMenuItem(const std::string description, const std::string command, const std::string parent_path) 
	: description(description), command(command), path(parent_path + " -> " + command)
{
}

AbstractMenuItem::~AbstractMenuItem()
{
}

std::string AbstractMenuItem::get_command()
{
	return command;
}

std::string AbstractMenuItem::get_description()
{
	return description;
}

std::string AbstractMenuItem::get_path()
{
	return path;
}


