#include <iostream>
#include "Contact.hpp"

Contact::Contact(int index, std::string first_name, std::string last_name, std::string nickname, 
		std::string phone_number, std::string darkest_secret) {
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	return;
}

Contact::Contact(void){
}

Contact::~Contact(void){
}

void	Contact::printContactLine(void) {
	std::cout << "|       " << this->index << "|";
	printField(first_name);
	printField(last_name);
	printField(nickname);
	std::cout << std::endl;
}

void	Contact::printContactFull(void) {
	std::cout << "Index: " << this->index << "\n";
	std::cout << "First Name: " << this->first_name << "\n";
	std::cout << "Last Name: " << this->last_name << "\n";
	std::cout << "Nickname: " << this->nickname << "\n";
	std::cout << "Phone Number: " << this->phone_number << "\n";
	std::cout << "Darkest Secret: " << this->darkest_secret << "\n";
}
