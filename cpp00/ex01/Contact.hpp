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
	Contact(int input_index, std::string input_first_name, std::string input_last_name, std::string input_nickname, 
		std::string input_phone_number, std::string input_darkest_secret);
	Contact();
	~Contact();
	void	print_contact_line();
	void	print_contact_full();
};

void	print_field(std::string str);
bool	str_is_digit(std::string str);

#endif