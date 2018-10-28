#pragma once
#include <vector>
#include "VirtualMenuItem.h"
#include <map>

std::vector<VirtualMenuItem*> get_menu_items();

std::map<std::string, VirtualMenuItem*> get_map_of_menu_items();
