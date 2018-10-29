#pragma once
#include "VirtualAction.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

class AddTable : public VirtualAction
{
public:
	AddTable(std::vector<Table*>* table_vector);
	~AddTable();

	void perform_action() const override;

private:
	//TODO: this actually isn't readonly, might have to remove const qualifier
	std::vector<Table*>* const table_vector;
};

class PrintTable: public VirtualAction
{
public:
	PrintTable(std::vector<Table*>* table_vector);
	~PrintTable();

	void perform_action() const override;

private:
	std::vector<Table*>* const table_vector{};
};