#include  "pch.h"
#include "actions.h"
#include "../../Laboratorium 1/Laboratorium 1/main_menu.h"

AddTable::AddTable(std::vector<Table*>* table_vector)
	:VectorBasedAction(table_vector)
{
	
}

AddTable::~AddTable()
{
	//TODO: give this a thought later!
	//if I do
	//delete table_vector
	//here, other clients won't be able to either delete or access the vector properly
}

//TODO: more complex implementation
void AddTable::perform_action() const
{
	add_table(*table_vector);
}
//-----------------------------------------------------------------------------

PrintOneTable::PrintOneTable(std::vector<Table*>* table_vector)
	:VectorBasedAction(table_vector)
{
	
}

PrintOneTable::~PrintOneTable()
{
	//like mentioned earlier
}

void PrintOneTable::perform_action() const
{
	print_one_table(*table_vector);
}
//-----------------------------------------------------------------------------

PrintAllTables::PrintAllTables(std::vector<Table*>* table_vector):
	VectorBasedAction(table_vector)
{
	
}

PrintAllTables::~PrintAllTables()
{
	
}

void PrintAllTables::perform_action() const
{
	print_all_tables(*table_vector);
}










