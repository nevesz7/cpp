#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <iomanip>

class	Data
{
	private:
		bool		boo;
		char		ch;
		int			nbr;
		std::string	str;

	public:
		Data();
		Data(const Data &copy);
		Data(bool boo, char ch, int nbr, std::string str);
		Data	&operator=(const Data &data);
		~Data();

		std::string	getStr(void) const;
		int			getNbr(void) const;
		char		getChar(void) const;
		bool		getBool(void) const;
};

std::ostream &operator<<(std::ostream &out, Data const &data);

#endif
