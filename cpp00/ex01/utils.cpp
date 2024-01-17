#include <iostream>
#include <cstring>

void printField(std::string str) {
	if (str.length() > 10) 
	{
		std::cout << str.substr(0, 9) << ".|";
	}
	else {
		for (size_t spaces = 0; spaces < (10 - str.length()); spaces++)
		{
			std::cout << " ";
		}
		std::cout << str << "|";
	}
}

bool strIsDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
