#pragma once
#include "VirtualAction.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

/**
 * Interface class for actions that work on a vector of Table objects
 */
class TableAction : public VirtualAction
{
public:
	TableAction(std::vector<Table*>* table_vector);
	virtual ~TableAction();

	/**
	 * Virtual method, containing action that will be performed.
	 */
	void perform_action() const override = 0;
protected:
	//TODO: just to be sure, can this reaaaaally be const?
	/**
	 * Vector containing Table objects, on which an action is going to be performed.
	 */
	std::vector<Table*>* const table_vector;
};

