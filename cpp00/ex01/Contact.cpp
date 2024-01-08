#include <iostream>
#include "Contact.hpp"

Contact::Contact(int input_index, std::string input_first_name, std::string input_last_name, std::string input_nickname, 
		std::string input_phone_number, std::string input_darkest_secret) {
	index = input_index;
	first_name = input_first_name;
	last_name = input_last_name;
	nickname = input_nickname;
	phone_number = input_phone_number;
	darkest_secret = input_darkest_secret;
	return;
}

Contact::Contact(void){
}

Contact::~Contact(void){
}

void	Contact::print_contact_line(void) {
	std::cout << "|       " << index << "|";
	print_field(first_name);
	print_field(last_name);
	print_field(nickname);
	std::cout << std::endl;
}

void	Contact::print_contact_full(void) {
	std::cout << "Index: " << index << "\n";
	std::cout << "First Name: " << first_name << "\n";
	std::cout << "Last Name: " << last_name << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone Number: " << phone_number << "\n";
	std::cout << "Darkest Secret: " << darkest_secret << "\n";
}
