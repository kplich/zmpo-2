#include "pch.h"
#include "AbstractMenuItem.h"
#include <iostream>


//TODO: member initializer list instead of usual constructor!
AbstractMenuItem::AbstractMenuItem(const std::string description, const std::string command) 
	: description(description), command(command)
{
	std::cout << "Parametrized AbstractMenuItem constructor, " << command << "\n";
}


AbstractMenuItem::~AbstractMenuItem()
{
	std::cout << "AbstractMenuItem destructor, " << command << "\n";
}


std::string AbstractMenuItem::get_command() const
{
	return command;
}

std::string AbstractMenuItem::get_description() const
{
	return description;
}


