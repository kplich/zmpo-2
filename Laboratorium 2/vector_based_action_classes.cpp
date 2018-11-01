#include  "pch.h"
#include "vector_based_action_classes.h"
#include "action_implementations.h"
#include <iostream>

AddTable::AddTable(std::vector<Table*>* table_vector)
	:TableAction(table_vector)
{
	std::cout << "AddTable action constructor.\n";
}

AddTable::~AddTable()
{
	std::cout << "AddTable action destructor.\n";
}

void AddTable::perform_action() const
{
	add_table(table_vector);
}
//-----------------------------------------------------------------------------

PrintOneTable::PrintOneTable(std::vector<Table*>* table_vector)
	:TableAction(table_vector)
{
	std::cout << "PrintOneTable action constructor.\n";

}

PrintOneTable::~PrintOneTable()
{
	std::cout << "PrintOneTable action destructor.\n";
}

void PrintOneTable::perform_action() const
{
	print_one_table(table_vector);
}
//-----------------------------------------------------------------------------

PrintAllTables::PrintAllTables(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	std::cout << "PrintAllTables action constructor.\n";

}

PrintAllTables::~PrintAllTables()
{
	std::cout << "PrintAllTables action destructor.\n";
}

void PrintAllTables::perform_action() const
{
	print_all_tables(table_vector);
}
//-----------------------------------------------------------------------------

CloneTable::CloneTable(std::vector<Table*>* table_vector) :
	TableAction(table_vector)
{
	std::cout << "CloneTable action constructor.\n";

}

CloneTable::~CloneTable()
{
	std::cout << "CloneTable action destructor.\n";
}

void CloneTable::perform_action() const
{
	clone_table(table_vector);
}
//------------------------------------------------------------------------------

DeleteOneTable::DeleteOneTable(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	std::cout << "DeleteOneTable action constructor.\n";

}

DeleteOneTable::~DeleteOneTable()
{
	std::cout << "DeleteOneTable action destructor.\n";
}

void DeleteOneTable::perform_action() const
{
	delete_one_table(table_vector);
}
//------------------------------------------------------------------------------

DeleteAllTables::DeleteAllTables(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	std::cout << "DeleteAllTables action constructor.\n";

}

DeleteAllTables::~DeleteAllTables()
{
	std::cout << "DeleteAllTables action destructor.\n";
}

void DeleteAllTables::perform_action() const
{
	delete_all_tables(table_vector);
}
//-----------------------------------------------------------------------------

RenameTable::RenameTable(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	std::cout << "RenameTable action constructor.\n";

}

RenameTable::~RenameTable()
{
	std::cout << "RenameTable action destructor.\n";

}

void RenameTable::perform_action() const
{
	rename_table(table_vector);
}
//-----------------------------------------------------------------------------

ResizeTable::ResizeTable(std::vector<Table*>* table_vector) :
	TableAction(table_vector)
{
	std::cout << "ResizeTable action constructor.\n";

}

ResizeTable::~ResizeTable()
{
	std::cout << "ResizeTable action destructor.\n";

}

void ResizeTable::perform_action() const
{
	resize_table(table_vector);
}
//-----------------------------------------------------------------------------

PutValue::PutValue(std::vector<Table*>* table_vector):
	TableAction(table_vector)
{
	std::cout << "PutValue action constructor.\n";

}

PutValue::~PutValue()
{
	std::cout << "PutValue action destructor.\n";

}

void PutValue::perform_action() const
{
	put_value(table_vector);
}







