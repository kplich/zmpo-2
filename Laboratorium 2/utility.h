#pragma once
#include <vector>
#include "VirtualMenuItem.h"
#include <map>
#include "MenuCommand.h"
#include "ReturnAction.h"

MenuCommand* const return_command = new MenuCommand(new ReturnAction(), "Return to previous menu", "return");

std::map<std::string, VirtualMenuItem*>* get_map_of_menu_items();

void insert_item_into_map(std::map<std::string, VirtualMenuItem*>* item_map, VirtualMenuItem* menu_item);

std::string get_input_from_user();