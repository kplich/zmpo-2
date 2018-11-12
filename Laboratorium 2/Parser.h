#pragma once
#include "../ParsingStack/ParsingStack.h"
#include "Menu.h"

class Parser
{
public:
	Parser(std::string input);
	~Parser();

	Menu* parse();

private:
	ParsingStack* source;

	AbstractMenuItem* parse_item(std::string parent_path);

	Menu* parse_menu(Menu* root, std::string parent_path);
	Command* parse_command(std::string parent_path);

	Menu* parse_beginning_of_menu(Menu* root, std::string parent_path);

	//TODO: deal with possibility of unclosed string ('........)
	bool extract_string(std::string& result);

	bool parse_char(char expected);

	void parsing_error(char expected, char found);

	void parsing_error(std::string message);

};

