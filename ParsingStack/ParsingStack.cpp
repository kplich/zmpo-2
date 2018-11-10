#include "ParsingStack.h"
#include <string>

ParsingStack::ParsingStack(std::string string)
{
	//deallocated in destructor
	this->source = new std::list<char>(string.begin(), string.end());
	this->position_counter = 0;
}

ParsingStack::~ParsingStack()
{
	delete source;
}

char ParsingStack::pop_one()
{
	char first = source->front();
	source->pop_front();

	++position_counter;

	return first;
}

std::string ParsingStack::pop_until_char_found(char ending_character)
{
	std::string result;

	char current_top = pop_one();

	while(current_top != ending_character)
	{
		result += current_top;
		current_top = pop_one();
	}

	return result;
}

int ParsingStack::get_position()
{
	return position_counter;
}



