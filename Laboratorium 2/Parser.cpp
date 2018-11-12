#include "pch.h"
#include "Parser.h"
#include "DefaultAction.h"
#include <iostream>

static const char begin_and_end_string = '\'';

static const char begin_menu = '(';
static const char description_command_separator = ',';
static const char command_children_separator = ';';
static const char children_separator = ',';
static const char end_menu = ')';

static const char begin_command = '[';
static const char separator = ',';
static const char end_command = ']';

Parser::Parser(std::string input)
{
	this->source = new ParsingStack(input);
}

Parser::~Parser()
{
	delete source;
}

Menu* Parser::parse()
{
	return parse_menu(nullptr, "");
}


AbstractMenuItem* Parser::parse_item(Menu* root, std::string parent_path)
{
	char found;

	if (!source->peek(found))
	{
		end_of_string_error();
		return nullptr;
	}

	switch (found)
	{
		case begin_menu:
		{
			return parse_menu(root, parent_path);
		}
		case begin_command:
		{
			return parse_command(parent_path);
		}
		default:
		{
			parsing_error("Expected: " + begin_menu + " or " + begin_command + ", found: '" + found + "'.");
			return nullptr;
		}
	}
}


Menu* Parser::parse_menu(Menu* root, std::string parent_path)
{
	std::string description;
	std::string command;

	//TODO: separate parsing strings and parsing children

	Menu* result_item = parse_beginning_of_menu(root, parent_path);

	if (result_item == nullptr)
	{
		return nullptr;
	}

	//parse command-children delimiter, any error will be signalled from the method
	if (!parse_char(command_children_separator))
	{
		return nullptr;
	}

	//we need to know what's at the top of the stack,
	//but so do the methods later
	char top;
	if (!source->peek(top)) {
		end_of_string_error();
		return nullptr;
	}

	//all children parsed here
	while (top != end_menu)
	{
		//parse a child item. any errors will be signalled in this call
		AbstractMenuItem* child_item = parse_item(result_item, result_item->get_path());

		if (child_item == nullptr)
		{
			//if there was an error during parsing a child,
			//the whole string should get invalidated
			return nullptr;
		}

		result_item->add_item(child_item);

		//parse children separator, any error will be signalled here
		if (!parse_char(children_separator))
		{
			return nullptr;
		}

		if (!source->peek(top))
		{
			end_of_string_error();
			return nullptr;
		}
	}

	//parse the finishing char
	parse_char(end_menu);

	//this message is only relevant when we're parsing main menu
	if (root == nullptr && !source->empty())
	{
		parsing_error("Unexpected characters found after menu definition.\nMenu parsing did not fail, but the results may be different than expected.");
	}

	return result_item;
}

Menu* Parser::parse_beginning_of_menu(Menu* root, std::string parent_path)
{
	std::string description;
	std::string command;

	//parse beginning of menu
	if (!parse_char(begin_menu))
	{
		return nullptr;
	}

	//parse description
	if (!extract_string(description)) 
	{
		return nullptr;
	}

	//parse description-command delimiter
	if (!parse_char(description_command_separator))
	{
		return nullptr;
	}

	//extract command
	if (!extract_string(command))
	{
		return nullptr;
	}

	return new Menu(description, command, root, parent_path);
}




Command* Parser::parse_command(std::string parent_path)
{
	std::string description;
	std::string command;
	std::string help;

	if (!parse_char(begin_command)) //parse beginning of command '['
	{
		return nullptr;
	}

	if(!extract_string(description)) //parse description
	{
		return nullptr;
	}

	if (!parse_char(separator)) //parse separator ','
	{
		return nullptr;
	}

	if (!extract_string(command)) //parse command
	{
		return nullptr;
	}

	if (!parse_char(separator)) //parse separator ','
	{
		return nullptr;
	}

	if (!extract_string(help)) //parse help
	{
		return nullptr;
	}

	if (!parse_char(end_command)) //parse end of command ']'
	{
		return nullptr;
	}

	return new Command(description, command, parent_path, new DefaultAction(), help);
}

bool Parser::extract_string(std::string& result)
{
	char found;

	if(!source->pop_one(found))
	{
		return false;
	}

	if(found != begin_and_end_string)
	{
		parsing_error(begin_and_end_string, found);
		return false;
	}

	result = "";

	if (!source->pop_until_char_found(result, begin_and_end_string))
	{
		return false;
	}

	return true;
}

bool Parser::parse_char(char expected)
{
	char found;

	if (!source->pop_one(found))
	{
		return false;
	}

	if(found != expected)
	{
		parsing_error(expected, found);
		return false;
	}

	return true;
}

void Parser::parsing_error(char expected, char found)
{
	std::cout << "Error at position " << source->get_position() << ".\n";
	std::cout << "Expected: " << expected << ", found: " << found << ".\n";
}

void Parser::parsing_error(std::string message)
{
	std::cout << "Error at position " << source->get_position() << ".\n";
	std::cout << message << "\n";
}

void Parser::end_of_string_error()
{
	std::cout << "Error at position " << source->get_position() << ".\n";
	std::cout << "Reached end of string too early.\n";
	
}




