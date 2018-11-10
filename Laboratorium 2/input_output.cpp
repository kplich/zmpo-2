#include "pch.h"
#include <sstream>
#include <iostream>
#include <string>
#include "input_output.h"

//TODO: extract out strings

std::string int_to_string(int number)
{
	std::ostringstream string_stream;
	string_stream << number;
	return string_stream.str();
}

int string_to_int(std::string string)
{
	int result;
	std::istringstream iss(string);
	iss >> result;

	return result;
}

std::string get_user_input()
{
	std::string result;
	std::getline(std::cin, result);

	std::cout << "\n";
	return result;
}

bool get_int_input(int& output, int range_min, int range_max)
{
	//if the range is invalid, return false
	if (range_min > range_max)
	{
		return false;
	}

	std::string user_input = get_user_input();
	int temp = string_to_int(user_input);

	if (temp < range_min || temp > range_max)
	{
		return false;
	}
	else
	{
		std::string temp_as_string = int_to_string(temp);

		//check if there are letters after the number, eg. 123xd
		if (temp_as_string == user_input)
		{
			output = temp;
			return true;
		}
		return false;
	}
}

int loop_until_valid_int(int range_min, int range_max)
{
	int result;
	bool valid;

	do
	{
		std::cout << "Podaj liczbe z zakresu " << range_min << " - " << range_max << "\n";
		valid = get_int_input(result, range_min, range_max);

		if (!valid)
		{
			std::cout << "Numer nie jest prawidlowy.\n";
		}
	} while (!valid);

	return result;
}

void communicate_success(bool operation_succeeded)
{
	if (operation_succeeded)
	{
		std::cout << "Operacja przebiegla pomyslnie.\n";
	}
	else
	{
		std::cout << "Podczas operacji wystapil blad.\n";
	}
}

void unknown_code()
{
	std::cout << "Nie wiem, jaka operacje wykonac.\n";
}
