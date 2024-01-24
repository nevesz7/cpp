#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>

# define BUFFER_SIZE 3

bool		checkInputFile(const std::ifstream& fin);
bool		checkOutputFile(const std::ofstream& fout);

std::string	readFile(std::string inputFile);
void		writeInFile(std::string outputFile, std::string bigString,
	std::string before,	std::string after);

#endif