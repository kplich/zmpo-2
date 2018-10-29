#include  "pch.h"
#include "vector_based_action_classes.h"
#include "action_implementations.h"

AddTable::AddTable(std::vector<Table*>* table_vector)
	:TableAction(table_vector)
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
	add_table(table_vector);
}
//-----------------------------------------------------------------------------

PrintOneTable::PrintOneTable(std::vector<Table*>* table_vector)
	:TableAction(table_vector)
{
	
}

PrintOneTable::~PrintOneTable()
{
	//like mentioned earlier
}

void PrintOneTable::perform_action() const
{
	print_one_table(table_vector);
}
//-----------------------------------------------------------------------------

PrintAllTables::PrintAllTables(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	
}

PrintAllTables::~PrintAllTables()
{
	
}

void PrintAllTables::perform_action() const
{
	print_all_tables(table_vector);
}
//-----------------------------------------------------------------------------

CloneTable::CloneTable(std::vector<Table*>* table_vector) :
	TableAction(table_vector)
{
	
}

CloneTable::~CloneTable()
{
	
}

void CloneTable::perform_action() const
{
	clone_table(table_vector);
}
//------------------------------------------------------------------------------

DeleteOneTable::DeleteOneTable(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	
}

DeleteOneTable::~DeleteOneTable()
{
	
}

void DeleteOneTable::perform_action() const
{
	delete_one_table(table_vector);
}
//------------------------------------------------------------------------------

DeleteAllTables::DeleteAllTables(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	
}

DeleteAllTables::~DeleteAllTables()
{
	
}

void DeleteAllTables::perform_action() const
{
	delete_all_tables(table_vector);
}
//-----------------------------------------------------------------------------

RenameTable::RenameTable(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	
}

RenameTable::~RenameTable()
{
	
}

void RenameTable::perform_action() const
{
	
}
//-----------------------------------------------------------------------------

ResizeTable::ResizeTable(std::vector<Table*>* table_vector) :
	TableAction(table_vector)
{
	
}

ResizeTable::~ResizeTable()
{
	
}

void ResizeTable::perform_action() const
{
	resize_table(table_vector);
}
//-----------------------------------------------------------------------------

PutValue::PutValue(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	
}

PutValue::~PutValue()
{
	
}

void PutValue::perform_action() const
{
	put_value(table_vector);
}







