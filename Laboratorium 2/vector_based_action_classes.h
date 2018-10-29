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

//TODO: uhm, is it exactly a vector-based action???
class EditTable: public VectorBasedAction
{
public:
	EditTable(std::vector<Table*>* table_vector);
	~EditTable();

	void perform_action() const override;
};

class CloneTable: public VectorBasedAction
{
public:
	CloneTable(std::vector<Table*>* table_vector);
	~CloneTable();

	void perform_action() const override;
};

class DeleteOneTable: public VectorBasedAction
{
public:
	DeleteOneTable(std::vector<Table*>* table_vector);
	~DeleteOneTable();

	void perform_action() const override;
};

class DeleteAllTables: public VectorBasedAction
{
public:
	DeleteAllTables(std::vector<Table*>* table_vector);
	~DeleteAllTables();

	void perform_action() const override;
};