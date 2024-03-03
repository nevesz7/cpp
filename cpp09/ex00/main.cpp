#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Input Error. Usage: \"./btc <input_file>\"" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.readData("data.csv");
		btc.readInput(std::string(argv[1]));
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}