#pragma once
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "VectorBasedAction.h"

/**
 * Class representing adding a table to the vector.
 */
class AddTable : public VectorBasedAction
{
public:
	AddTable(std::vector<Table*>* table_vector);
	~AddTable();

	void perform_action() const override;
};

class PrintOneTable: public VectorBasedAction
{
public:
	PrintOneTable(std::vector<Table*>* table_vector);
	~PrintOneTable();

	void perform_action() const override;
};

class PrintAllTables: public VectorBasedAction
{
public:
	PrintAllTables(std::vector<Table*>* table_vector);
	~PrintAllTables();

	void perform_action() const override;
};