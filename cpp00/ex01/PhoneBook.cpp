#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	counter = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::show_book(void) {
	std::cout << "|   Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < counter && i < 8; i++)
	{
		contacts[i].print_contact_line();
	}
}

void	PhoneBook::add_contact(Contact contact, int index) {
	contacts[index] = contact;
}

void	PhoneBook::show_contact(int index) {
	contacts[index].print_contact_full();
}