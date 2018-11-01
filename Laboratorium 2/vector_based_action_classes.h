#pragma once
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "TableAction.h"

/**
 * Class representing adding a table to the vector.
 */
class AddTable : public TableAction
{
public:
	AddTable(std::vector<Table*>* table_vector);
	~AddTable();

	void perform_action() const override;
};

class PrintOneTable: public TableAction
{
public:
	PrintOneTable(std::vector<Table*>* table_vector);
	~PrintOneTable();

	void perform_action() const override;
};

class PrintAllTables: public TableAction
{
public:
	PrintAllTables(std::vector<Table*>* table_vector);
	~PrintAllTables();

	void perform_action() const override;
};

class CloneTable: public TableAction
{
public:
	CloneTable(std::vector<Table*>* table_vector);
	~CloneTable();

	void perform_action() const override;
};

class DeleteOneTable: public TableAction
{
public:
	DeleteOneTable(std::vector<Table*>* table_vector);
	~DeleteOneTable();

	void perform_action() const override;
};

class DeleteAllTables: public TableAction
{
public:
	DeleteAllTables(std::vector<Table*>* table_vector);
	~DeleteAllTables();

	void perform_action() const override;
};

class RenameTable: public TableAction
{
public:
	RenameTable(std::vector<Table*>* table_vector);
	~RenameTable();

	void perform_action() const override;
};

class ResizeTable: public TableAction
{
public:
	ResizeTable(std::vector<Table*>* table_vector);
	~ResizeTable();

	void perform_action() const override;
};

class PutValue: public TableAction
{
public:
	PutValue(std::vector<Table*>* table_vector);
	~PutValue();

	void perform_action() const override;
};