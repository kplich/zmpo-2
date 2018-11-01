#include "pch.h"
#include "AbstractMenuItem.h"

//member initializer list instead of usual constructor!
AbstractMenuItem::AbstractMenuItem(const std::string description, const std::string command) 
	: description(description), command(command)
{
}

AbstractMenuItem::~AbstractMenuItem()
{
}

std::string AbstractMenuItem::get_command() const
{
	return command;
}

std::string AbstractMenuItem::get_description() const
{
	return description;
}


