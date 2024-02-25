#include "header.hpp"

int strToInt(std::string literal)
{
	return atoi(literal.c_str());
}

char intToChar(int i)
{
	return (i >= 32 && i <= 126) ? static_cast<char>(i) : static_cast<char>(0);
}

double intToDouble(int i)
{
	return static_cast<double>(i);
}

float intToFloat(int i)
{
	return static_cast<float>(i);
}