#pragma once
#include "VirtualMenuItem.h"
#include <map>
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

VirtualMenuItem* get_main_menu(std::vector<Table*>* table_vector);

//TODO: this is probably to be moved to Menu class
void insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item);

std::string get_input_from_user();