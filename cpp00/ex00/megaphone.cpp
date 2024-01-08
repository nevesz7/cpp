#include <iostream>
#include <cstring>

int main (int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int y = 1; y < argc; y++)
		{
			for (unsigned int x = 0; x < strlen(argv[y]); x++)
			std::cout << char((toupper(argv[y][x])));
		}
	} 
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
}
