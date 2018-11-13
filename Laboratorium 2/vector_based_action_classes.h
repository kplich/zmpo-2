#pragma once
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"
#include "AbstractAction.h"

/**
 * Interface class for actions that work on a vector of Table objects
 */
class TableAction : public AbstractAction
{
public:
	TableAction(std::vector<Table*>* table_vector);

	virtual ~TableAction();

	/**
	 * Virtual method, containing action that will be performed.
	 */
	void perform_action() const override = 0;
protected:
	/**
	 * Vector containing Table objects, on which an action is going to be performed.
	 */
	std::vector<Table*>* table_vector;
};

//---------------------------------------------------------------------------------------------

const std::string add_table_help = "Here you can create a new table, set its name and length.";
const std::string add_table_description = "Add a new table";
const std::string add_table_command = "add";

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

//--------------------------------------------------------------------

const std::string print_one_help = "Print contents of the chosen table.";
const std::string print_one_description = "Print one of the tables";
const std::string print_one_command = "print one";

class PrintOneTable: public TableAction
{
public:
	PrintOneTable(std::vector<Table*>* table_vector);
	~PrintOneTable();

	void perform_action() const override;
};

//-----------------------------------------------------------------------

const std::string print_all_description = "Print all tables";
const std::string print_all_command = "print_all";
const std::string print_all_help = "Print information about all added tables.";

class PrintAllTables: public TableAction
{
public:
	PrintAllTables(std::vector<Table*>* table_vector);
	~PrintAllTables();

	void perform_action() const override;
};

//---------------------------------------------------------------

const std::string clone_table_help = "Add a copy of a chosen table to the collection.";
const std::string clone_table_description = "Clone chosen table";
const std::string clone_table_command = "clone";

class CloneTable: public TableAction
{
public:
	CloneTable(std::vector<Table*>* table_vector);
	~CloneTable();

	void perform_action() const override;
};

//-------------------------------------------------------------------------------

const std::string delete_one_help = "Delete chosen table from the collection.";
const std::string delete_one_description = "Delete single, chosen table";
const std::string delete_one_command = "delete one";

class DeleteOneTable: public TableAction
{
public:
	DeleteOneTable(std::vector<Table*>* table_vector);
	~DeleteOneTable();

	void perform_action() const override;
};

//-----------------------------------------------------------------------------------

const std::string delete_all_help = "Delete ALL tables from the collection.";
const std::string delete_all_description = "Delete all tables";
const std::string delete_all_command = "delete all";

class DeleteAllTables: public TableAction
{
public:
	DeleteAllTables(std::vector<Table*>* table_vector);
	~DeleteAllTables();

	void perform_action() const override;
};

//--------------------------------------------------------------------

const std::string rename_table_help = "Change the name of a chosen table.";
const std::string rename_table_description = "Rename chosen table";
const std::string rename_table_command = "rename";

class RenameTable: public TableAction
{
public:
	RenameTable(std::vector<Table*>* table_vector);
	~RenameTable();

	void perform_action() const override;
};

//------------------------------------------------------------------------
const std::string resize_table_description = "Resize chosen table";
const std::string resize_table_command = "resize";
const std::string resize_table_help = "Change the size of a chosen table.\nIf you shrink the table, your information may be lost.";

class ResizeTable: public TableAction
{
public:
	ResizeTable(std::vector<Table*>* table_vector);
	~ResizeTable();

	void perform_action() const override;
};

//--------------------------------------------------------------------------------

const std::string put_value_description = "Put value into the chosen table";;
const std::string put_value_command = "put value";
const std::string put_value_help = "Change a desired value in one of the chosen tables.";

class PutValue: public TableAction
{
public:
	PutValue(std::vector<Table*>* table_vector);
	~PutValue();

	void perform_action() const override;
};