#include "pch.h"
#include "Parser.h"
#include <iostream>
#include "special_actions.h"

static const std::string error_at_pos = "error at position";
static const std::string expected_msg = "expected";
static const std::string found_msg = "found";
static const std::string end_of_string = "reached end of string.";

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
		case Menu::begin_menu:
		{
			return parse_menu(root, parent_path);
		}
		case Command::begin_command:
		{
			return parse_command(parent_path);
		}
		default:
		{
			std::string expected_chars;
			(expected_chars += Menu::begin_menu) += Command::begin_command;
			parsing_error(expected_chars, found);
			return nullptr;
		}
	}
}

Menu* Parser::parse_menu(Menu* root, std::string parent_path)
{
	Menu* result_item = parse_beginning_of_menu(root, parent_path);

	//if parsing beginning failed, discard the result
	if (result_item == nullptr)
	{
		delete result_item;
		return nullptr;
	}

	//parse command-children delimiter, any error will be signalled from the method
	if (!parse_char(Menu::command_children_separator))
	{
		delete result_item;
		return nullptr;
	}

	//check what's at the top of the stack (but don't pop yet, we're gonna need it)
	char top;

	//if we reach the end of string, signal an error
	if (!source->peek(top)) {

		std::string expected_chars;
		((expected_chars += Menu::begin_menu) += Command::begin_command) += Menu::end_menu;
		parsing_error(expected_chars, 0);

		delete result_item;
		return nullptr;
	}

	//children parsed here
	while (top != Menu::end_menu)
	{
		//parse a child item. any errors will be signalled in this call
		AbstractMenuItem* child_item = parse_item(result_item, result_item->get_path());

		//if parsing child didnt succeed, discard the whole result
		if (child_item == nullptr)
		{
			delete result_item;
			return nullptr;
		}

		result_item->add_item(child_item);

		//peek at the next character
		//if we reach the end of the string, signal an error
		if(!source->peek(top))
		{
			std::string expected_chars;
			(expected_chars += Menu::children_separator) += Menu::end_menu;
			parsing_error(expected_chars, 0);

			delete result_item;
			return nullptr;
		}

		switch(top)
		{
			case Menu::children_separator:
			{
				//we know this succeeds, so no check here
				//we can attempt to parse another child in next repetition of the loop
				parse_char(Menu::children_separator);
				break;
			}
			case Menu::end_menu:
			{
				//don't do anything, the loop will break in next iteration
				//this is the only place from which you can exit this loop
				break;
			}
			default:
			{
				std::string expected_chars;
				(expected_chars += Menu::children_separator) += Menu::end_menu;
				parsing_error(expected_chars, top);

				delete result_item;
				return nullptr;
			}
		}
	}

	//parse the closing char
	//no check, because the only way to exit the loop above is to reach menu ending character
	parse_char(Menu::end_menu);

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
	if (!parse_char(Menu::begin_menu))
	{
		return nullptr;
	}

	//parse description
	if (!extract_string(description)) 
	{
		return nullptr;
	}

	//parse description-command delimiter
	if (!parse_char(Menu::description_command_separator))
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

	if (!parse_char(Command::begin_command)) //parse beginning of command '['
	{
		return nullptr;
	}

	if(!extract_string(description)) //parse description
	{
		return nullptr;
	}

	if (!parse_char(Command::separator)) //parse separator ','
	{
		return nullptr;
	}

	if (!extract_string(command)) //parse command
	{
		return nullptr;
	}

	if (!parse_char(Command::separator)) //parse separator ','
	{
		return nullptr;
	}

	if (!extract_string(help)) //parse help
	{
		return nullptr;
	}

	if (!parse_char(Command::end_command)) //parse end of command ']'
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

	if(found != AbstractMenuItem::begin_and_end_string)
	{
		parsing_error(AbstractMenuItem::begin_and_end_string, found);
		return false;
	}

	result = "";

	if (!source->pop_until_char_found(result, AbstractMenuItem::begin_and_end_string))
	{
		parsing_error(AbstractMenuItem::begin_and_end_string, 0);
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
	std::cout << error_at_pos << ": " << source->get_position() << ".\n";

	if(found == 0)
	{
		std::cout << expected_msg << ": " << expected << "\n";
		std::cout << end_of_string << "\n";
	}
	else
	{
		std::cout << expected_msg << ": " << expected << "\n";
		std::cout << found_msg << ": " << found << "\n";
	}
	
}

void Parser::parsing_error(std::string expected, char found)
{
	std::cout << error_at_pos << ": " << source->get_position() << ".\n";
	std::cout << expected_msg << ":\n";

	for(int i = 0; i < expected.length(); ++i)
	{
		std::cout << expected[i] << "\t";
	}
	std::cout << "\n";

	if(found == 0)
	{
		std::cout << end_of_string << "\n";
	}
	else
	{
		std::cout << found_msg << ": " << found << ".\n";
	}
	
}

void Parser::parsing_error(std::string message)
{
	std::cout << error_at_pos << ": " << source->get_position() << ".\n";
	std::cout << message << "\n";
}

void Parser::end_of_string_error()
{
	std::cout << error_at_pos << ": " << source->get_position() << ".\n";
	std::cout << end_of_string << "\n";
	
}