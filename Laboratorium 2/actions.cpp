#include  "pch.h"
#include "actions.h"
#include "../../Laboratorium 1/Laboratorium 1/main_menu.h"

AddTable::AddTable(std::vector<Table*>* table_vector)
	:table_vector(table_vector)
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
PrintTable::PrintTable(std::vector<Table*>* table_vector)
	:table_vector(table_vector)
{
	
}

PrintTable::~PrintTable()
{
	//like mentioned earlier
}

void PrintTable::perform_action() const
{
	print_one_table(*table_vector);
}






