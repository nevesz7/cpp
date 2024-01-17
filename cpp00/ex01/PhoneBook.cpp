#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->counter = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::showBook(void) {
	std::cout << "|   Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < counter && i < 8; i++)
	{
		contacts[i].printContactLine();
	}
}

void	PhoneBook::addContact(Contact contact, int index) {
	contacts[index] = contact;
}

void	PhoneBook::showContact(int index) {
	contacts[index].printContactFull();
}