#include <string>

char strToChar(std::string literal)
{
	return ((char)literal[0]);
}

double charToDouble(char c)
{
    return static_cast<double>(c);
}

float charToFloat(char c)
{
    return static_cast<float>(c);
}

int charToInt(char c)
{
    return static_cast<int>(c);
}
