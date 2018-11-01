#pragma once
#include "AbstractMenuItem.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

AbstractMenuItem* get_main_menu(std::vector<Table*>* table_vector);

AbstractMenuItem* get_editing_menu(std::vector<Table*>* table_vector);