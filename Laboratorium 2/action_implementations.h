#pragma once //preprocessor directive used to prevent from multiple inclusions
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"


void print_all_tables(std::vector<Table*>* tables);
void print_one_table(std::vector<Table*>* tables);
void add_table(std::vector<Table*>* tables);
void edit_table(std::vector<Table*>* tables);
void clone_table(std::vector<Table*>* tables);
void delete_all_tables(std::vector<Table*>* tables);
void delete_one_table(std::vector<Table*>* tables);

/**
 * Helper method deallocating all the tables in a vector.
 * @param tables reference to the table vector that is supposed to be cleared.
 */
void deallocate_tables(std::vector<Table*>* tables);