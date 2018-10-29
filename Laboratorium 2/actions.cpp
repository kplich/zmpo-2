#include  "pch.h"
#include "actions.h"

AddTable::AddTable(std::vector<Table*>* table_vector)
	:table_vector(table_vector)
{

}

AddTable::~AddTable()
{
	//vector of Table objects isn't created here, that's why it also won't be deleted here
	//or should it be?
}

//TODO: more complex implementation
void AddTable::perform_action() const
{
	table_vector->push_back(new Table());
}



