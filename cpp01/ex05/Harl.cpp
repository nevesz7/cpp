#include "Harl.hpp"

void Harl::complain( std::string level ) {
	for (unsigned int x = 0; x < level.length(); x++)
		level[x] = char((toupper(level[x]))); //normalizing string to uppercase

	void (Harl::*fct_ptr[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
	}; //creates an array with 4 function pointers to Harl functions

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (i = 0; i < 4 && levels[i] != level; i++); 
	//iterates through the levels array checking if the input matches any of the levels
	//if it doenst, return an error message
	
	if (i >= 4)
	{
		std::cerr << "Not a valid function" << std::endl;
		return ;
	}

	(this->*fct_ptr[i])();
}

void Harl::debug(){
	std::cout << "Killing all bugs makes me a debugger, right? \t\tHarl hates bugs" << std::endl; 
}

void Harl::info(){
	std::cout << "The Eiffel Tower can be 15 cm taller during the summer. Harl hates summer" << std::endl;
}

void Harl::warning(){
	std::cout << "BE CAREFUL, YOU HAVE DANGEROUS THINGS IN THERE. \tHarl HATES DANGEROUS THINGS" << std::endl;
}

void Harl::error(){
	std::cout << "404 ANSWER NOT FOUND!! \t\t\t\t\tps: Harl hates errors" << std::endl;
}