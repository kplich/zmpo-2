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

AbstractMenuItem* Parser::parse_item(Menu* root, std::string parent_path)
{
	char found = source->peek();

	switch (found)
	{
		case begin_menu:
		{
			return parse_menu(root, parent_path);
			break;
		}
		case begin_command:
		{
			return parse_command(parent_path);
			break;
		}
		default:
		{
			return nullptr;
			break;
		}
	}
}


Menu* Parser::parse_menu(Menu* root, std::string parent_path)
{
	std::string description;
	std::string command;

	//TODO: separate parsing strings and parsing children

	Menu* result_item = parse_beginning_of_menu(root, parent_path);

	if (result_item != nullptr)
	{
		//parse command-children delimiter
		if (parse_char(command_children_separator))
		{
			//we need to know what's at the top of the stack,
			//but so do the methods later
			char top = source->peek();

			while (top != end_menu)
			{
				//parse a child item
				AbstractMenuItem* child_item = parse_item(root, parent_path);
				if(child_item != nullptr)
				{
					result_item->add_item(child_item);

					//parse children separator
					if(!parse_char(children_separator))
					{
						return nullptr;
					}
				}
				else
				{
					//if there was an error during parsing a child, the whole string should get invalidated.
					return nullptr;
				}
			}

			//parse the finishing char
			parse_char(end_menu);

			if(!source->empty())
			{
				parsing_error("Unexpected characters found after menu definition.\nMenu parsing did not fail, but the results may be different than expected.");
			}

			return result_item;
		}
	}

	return nullptr;
}

Menu* Parser::parse_beginning_of_menu(Menu* root, std::string parent_path)
{
	std::string description;
	std::string command;

	if (parse_char(begin_menu)) //parse beginning of menu
	{
		if (extract_string(description)) //parse description
		{
			//parse description-command delimiter
			if (parse_char(description_command_separator))
			{
				//extract command
				if (extract_string(command))
				{
					return new Menu(description, command, root, parent_path);
				}
			}
		}
	}

	return nullptr;
}


Command* Parser::parse_command(std::string parent_path)
{
	std::string description;
	std::string command;
	std::string help;

	//TODO: create a fluent API xDD
	if (parse_char(begin_command)) //parse beginning of command '['
	{
		if(extract_string(description)) //parse description
		{
			if (parse_char(separator)) //parse separator ','
			{
				if (extract_string(command)) //parse command
				{
					if (parse_char(separator)) //parse separator ','
					{
						if (extract_string(help)) //parse help
						{
							if (parse_char(end_command)) //parse end of command ']'
							{
								return new Command(
									description,
									command,
									parent_path,
									new DefaultAction(),
									help
								);
							}
						}
					}
				}
			}
		}
	}

	//if any of the previous condition fails, method returns a null pointer
	return nullptr;
}

bool Parser::extract_string(std::string& result)
{
	char found = source->pop_one();
	if(found == begin_and_end_string)
	{
		result = source->pop_until_char_found(begin_and_end_string);
		return true;
	}
	else
	{
		parsing_error(begin_and_end_string, found);
		return false;
	}
}

bool Parser::parse_char(char expected)
{
	char found = source->pop_one();

	if(found == expected)
	{
		return true;
	}
	else
	{
		parsing_error(expected, found);
		return false;
	}
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



