#pragma once
#include "VirtualAction.h"
#include <vector>
#include "../../Laboratorium 1/Laboratorium 1/Table.h"

class VectorBasedAction :
	public VirtualAction
{
public:
	VectorBasedAction(std::vector<Table*>* table_vector);
	virtual ~VectorBasedAction();

	void perform_action() const override = 0;
protected:
	//TODO: just to be sure, can this reaaaaally be const?
	std::vector<Table*>* const table_vector;
};

