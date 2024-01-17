#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
	int				index;
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;

	public:
	Contact(int index, std::string first_name, std::string last_name, std::string nickname, 
		std::string phone_number, std::string darkest_secret);
	Contact();
	~Contact();
	void	printContactLine();
	void	printContactFull();
};

void	printField(std::string str);
bool	strIsDigit(std::string str);

#endif