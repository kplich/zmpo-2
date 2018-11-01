#pragma once
#include "AbstractAction.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

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
	std::vector<Table*>* const table_vector;
};

