#pragma once
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

void print_all_tables(std::vector<Table*>* vector_of_tables);
void print_one_table(std::vector<Table*>* vector_of_tables);
void add_table(std::vector<Table*>* vector_of_tables);
void clone_table(std::vector<Table*>* vector_of_tables);
void delete_all_tables(std::vector<Table*>* vector_of_tables);
void delete_one_table(std::vector<Table*>* vector_of_tables);

/**
 * Helper method deallocating all the tables in a vector.
 * @param vector_of_tables reference to the table vector that is supposed to be cleared.
 */
void deallocate_tables(std::vector<Table*>* vector_of_tables);

Table* get_table_for_editing(std::vector<Table*>* vector_of_tables);

void rename_table(std::vector<Table*>* vector_of_tables);
void resize_table(std::vector<Table*>* vector_of_tables);
void put_value(std::vector<Table*>* vector_of_tables);