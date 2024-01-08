#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Contact.hpp"

std::string	read_number(void)
{
	std::string	phone_number;

	while (1) {
		std::cout << "Insert Phone Number of Contact:" << std::endl;
		std::getline(std::cin, phone_number);
		if (phone_number.length() > 0) {
			if (str_is_digit(phone_number))
				return phone_number;
			std::cout << "Phone number can only contain digits" << std::endl;
		} else {
			if (std::cin.eof())
				return "";
			std::cout << "No empty fields allowed" << std::endl; 
		}
	}
}

std::string	read_string(std::string message)
{
	std::string	str;

	while (1) {
		std::cout << message << std::endl;
		std::getline(std::cin, str);
		if (str.length() > 0) {
			return str;
		} else {
			if (std::cin.eof())
				return "";
			std::cout << "No empty fields allowed" << std::endl; 
		}
	}
}

Contact read_contact(int index)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	first_name = read_string("Insert First Name of Contact:");
	if (!first_name.length())
		std::exit(EXIT_FAILURE);
	last_name = read_string("Insert Last Name of Contact:");
	if (!last_name.length())
		std::exit(EXIT_FAILURE);
	nickname = read_string("Insert Nickname of Contact:");
	if (!nickname.length())
		std::exit(EXIT_FAILURE);
	phone_number = read_number();
	if (!phone_number.length())
		std::exit(EXIT_FAILURE);
	darkest_secret = read_string("Insert Darkest Secret of Contact:");
	if (!darkest_secret.length())
		std::exit(EXIT_FAILURE);

	Contact contact(index, first_name, last_name, nickname, phone_number, darkest_secret);

	return contact;
}