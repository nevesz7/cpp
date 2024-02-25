#include "header.hpp"

float strToFloat(std::string literal)
{
    return strtof(literal.c_str(), NULL);
}

char floatToChar(float f)
{
	return (f >= 32 && f <= 126) ? static_cast<char>(f) : static_cast<char>(0);
}

double floatToDouble(float f)
{
	return static_cast<double>(f);
}

int floatToInt(float f)
{
	return static_cast<int>(f + 0.5f);
}