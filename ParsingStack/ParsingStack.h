#pragma once
#include <list>

/**
 * Class simplifying parsing a string and keeping track of position in the string.
 */
class ParsingStack
{
public:
	ParsingStack(std::string string);
	~ParsingStack();

	char peek();

	/**
	 * Returns a character at the top of the stack
	 * @return a character at the top of the stack
	 */
	char pop_one();

	/**
	 * Pop a character from the string and check if it's equal to an expected character
	 */
	bool pop_equal_to(char expected);

	/**
	 * Returns a string based on chars popped until given character has been found.
	 * After returning the string, the stack doesn't contain the ending character.
	 * @param ending_character character that's supposed to terminate popping the characters
	 * @return a string containing all the characters popped until ending character has been found
	 * (the returned string doesn't contain the ending character)
	 */
	std::string pop_until_char_found(char ending_character);

	/**
	 * Returns current position in the input string.
	 * @return current position in the input string
	 */
	int get_position();

	/**
	 * @return true, if there are no elements in the stack, false otherwise
	 */
	bool empty();

private:
	/**
	 * Source of chars.
	 */
	std::list<char>* source;

	/**
	 * Number indicating position in the string - number of the last popped character.
	 */
	int position_counter;

	void parsing_error(char expected, char found);
};
