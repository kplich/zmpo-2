#include "pch.h"
#include "ParsingStack.h"
#include <string>
#include <iostream>

//TODO: prevent reaching end of list

ParsingStack::ParsingStack(std::string string)
{
	//deallocated in destructor
	this->source = new std::list<char>(string.begin(), string.end());
	this->position_counter = -1;
}

ParsingStack::~ParsingStack()
{
	delete source;
}

char ParsingStack::peek()
{
	if(!source->empty())
	{
		return source->front();
	}
	else
	{
		return 0; //TODO: error here!
	}
}

char ParsingStack::pop_one()
{
	if (!source->empty())
	{
		char first = source->front();
		source->pop_front();

		++position_counter;

		return first;
	}
	else return 0; //TODO: error here
}

bool ParsingStack::pop_equal_to(char expected)
{
	char found = pop_one();
	bool result = (found == expected);

	if(!result)
	{
		parsing_error(expected, found);
	}

	return result;
}


std::string ParsingStack::pop_until_char_found(char ending_character)
{
	std::string result;

	char current_top = pop_one();

	while(!source->empty() && current_top != ending_character)
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

bool ParsingStack::empty()
{
	return source->empty();
}

void ParsingStack::parsing_error(char expected, char found)
{
	std::cout << "Error at position " << position_counter << ".\n";
	std::cout << "Expected: " << expected << ", found: " << found << ".\n";
}




