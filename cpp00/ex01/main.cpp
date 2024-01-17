#include "PhoneBook.hpp"

int	getIndex(int counter) {
	std::string line;
	int			nbr;

	while (1)
	{
		std::cout << "Insert the index of the contact you want more information about" << std::endl;
		std::getline(std::cin, line);
		if (std::cin.eof())
			return 0;
		if (line.length() != 1)
			std::cout << "\tPlease insert only one character" << std::endl;
		else if (strIsDigit(line))
		{
			nbr = (int)line[0] - 48;
			if (nbr >= counter || nbr > 7)
				std::cout << "\tThere is no contact with this index, please try again" << std::endl;
			else
				return nbr;
		}
		else
			std::cout << "\tThat is not a number" << std::endl;
	}
}

int main (void)
{
	PhoneBook	phoneBook;
	Contact		contact;
	std::string	str;
	int i = 0;

	while (1)
	{
		std::cout << "Choose between: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof() || str == "EXIT")
			return 0;
		if (str == "SEARCH") {
			phoneBook.showBook();
			if (phoneBook.counter != 0)
			{
				int index = getIndex(phoneBook.counter);
				phoneBook.showContact(index);
			}
			else 
			{
				std::cout << "\tThere are no valid contacts" << std::endl;
			}
		}
		if (str == "ADD")
		{
			contact = readContact(i % 8);
			phoneBook.addContact(contact, i % 8);
			phoneBook.counter++;
			i++;
		}
	}
}
