#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
	Contact	contacts[8];

	public:
	PhoneBook();
	~PhoneBook();
	int		counter;
	void	showBook();
	void	showContact(int index);
	void	addContact(Contact contact, int index);
};

Contact		readContact(int index);

#endif