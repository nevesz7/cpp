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
	void	show_book();
	void	show_contact(int index);
	void	add_contact(Contact contact, int index);
};

Contact		read_contact(int index);

#endif