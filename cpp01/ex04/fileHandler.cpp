#include "sed.hpp"

std::string	readFile(std::string inputFile) {
	std::ifstream	fin(inputFile.c_str());
	if (!checkInputFile(fin)) std::exit(EXIT_FAILURE);

	char *buffer = new char[BUFFER_SIZE];
	std::string bigString;

	while (fin.read(buffer, BUFFER_SIZE)) {
		std::string temp(buffer, fin.gcount());
		bigString += temp;
	}
	if (fin.gcount() > 0) {
    	std::string temp(buffer, fin.gcount());
    	bigString += temp;
	}
	delete []buffer;
	return bigString;
}

void	writeInFile(std::string outputFile, std::string bigString, std::string before, std::string after) {
	std::ofstream	fout(outputFile.c_str());
	if (!checkOutputFile(fout)) return ;

	size_t startPos = 0;
	size_t foundPos = bigString.find(before);

    while (foundPos != std::string::npos)
	{
        fout << bigString.substr(startPos, foundPos - startPos) << after;

        startPos = foundPos + before.length();
        foundPos = bigString.find(before, startPos);
    }
	fout << bigString.substr(startPos);
}