#pragma once
#include <string>

/**
 * "Pure virtual class created for Menu and MenuCommand to derive from???
 */
class VirtualMenuItem
{
public:
	VirtualMenuItem();
	virtual ~VirtualMenuItem();
private:
	std::string command;
	std::string name;
public:
	virtual void run() = 0;
};

