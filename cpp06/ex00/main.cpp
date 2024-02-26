#include "header.hpp"

int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		std::cerr << "Error: too many arguments" << std::endl;
		return 0;
	}
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return 0;
	}

	int i = getPrecision(argv[1]);
	std::cout << std::fixed << std::setprecision(i);
	ScalarConverter::convert(argv[1]);
}