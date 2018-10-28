#pragma once
#include <vector>
#include "VirtualMenuItem.h"
#include <map>

std::vector<VirtualMenuItem*>* get_menu_items();

std::map<std::string, VirtualMenuItem*>* get_map_of_menu_items();

void insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item);

std::string get_input_from_user();
