#include "RPN.hpp"
#include <iomanip>
#include <limits>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid input. Usage: ./RPN <rpn_expression>" << std::endl;
		return 1;
	}
	if (!isValidRPN(argv[1]))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	RPN rpn;
	std::cout << std::fixed << std::setprecision(0);
	try {
		std::cout << rpn.calculate(argv[1]) << std::endl;
	} catch (std::exception &e)	{
		std::cerr << e.what() << std::endl;
	}
}
