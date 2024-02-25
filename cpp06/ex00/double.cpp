#include "header.hpp"

double strToDouble(std::string literal)
{
	return std::strtod(literal.c_str(), NULL);
}

char doubleToChar(double d)
{
	return (d >= 32 && d <= 126) ? static_cast<char>(d) : static_cast<char>(0);
}

float doubleToFloat(double d)
{
    return static_cast<float>(d);
}

int doubleToInt(double d)
{
	return static_cast<int>(d + 0.5);
}

