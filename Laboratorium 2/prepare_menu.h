#pragma once
#include "AbstractMenuItem.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "Menu.h"

Menu* get_main_menu(std::vector<Table*>* table_vector);

AbstractMenuItem* get_editing_menu(std::vector<Table*>* table_vector, Menu* main_menu, std::string menu_path);