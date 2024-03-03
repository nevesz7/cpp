#include "PmergeMe.hpp"

bool checkArgs(char const **argv)
{
	if (!argv)
		return false;
	for (int i = 1; argv[i]; i++)
	{
		int j = 0;
		if (std::strlen(argv[i]) > 1 && argv[i][0] == '+')
			j++;
		for (; argv[i][j]; j++)
			if (!std::isdigit(argv[i][j]))
				return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: PmergeMe <num1 num2 num3 ... numX>" << std::endl;
		return 1;
	}
	try
	{
		if (!checkArgs(argv))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		PmergeMe p;
		p.run(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
