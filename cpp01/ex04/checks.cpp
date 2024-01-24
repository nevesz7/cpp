#include "sed.hpp"

bool checkInputFile(const std::ifstream& fin) {
    if (fin.is_open()) {
        return true;
    } else {
        std::cerr << "Failed to open the input file for reading." << std::endl;
        return false;
    }
}

bool checkOutputFile(const std::ofstream& fout) {
    if (fout.is_open()) {
        return true;
    } else {
        std::cerr << "Failed to open the output file for writing." << std::endl;
        return false;
    }
}