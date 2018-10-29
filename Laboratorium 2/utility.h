#pragma once
#include "VirtualMenuItem.h"
#include <map>
#include "Menu.h"

Menu* get_main_menu();

void insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item);

std::string get_input_from_user();