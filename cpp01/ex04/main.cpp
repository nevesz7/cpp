#include "sed.hpp"

int main(int argc, char *argv[]) {
	std::string	inputFile, outputFile, before, after;

	if (argc != 4)
	{
		std::cout << "Input error: wrong amount of arguments." << std::endl;
		std::cout << "Please insert the name of the desired file: ";
		std::getline(std::cin, inputFile);
		std::cout << "Please insert the string to be replaced: ";
		std::getline(std::cin, before);
		std::cout << "Please insert the string that should replace the first: ";
		std::getline(std::cin, after);
	}
	else
	{
		inputFile = argv[1];
		before = argv[2];
		after = argv[3];
	}

	std::string bigString = readFile(inputFile);

	outputFile = inputFile + ".replace";
	writeInFile(outputFile, bigString, before, after);
}
