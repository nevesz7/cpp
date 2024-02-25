#include "Data.hpp"

Data::Data(void) : boo(true), ch('c'), nbr(42), str("string")
{
	std::cout << "Default Data constructor called" << std::endl;
}

Data::Data(bool boo, char ch, int nbr, std::string str) : boo(boo), ch(ch), nbr(nbr), str(str)
{
	std::cout << "Parameter Data constructor called" << std::endl;
}

Data::Data(const Data& copy) {
    std::cout << "Copy Data constructor called" << std::endl;
	*this = copy;
}

Data& Data::operator=(const Data& data) {
    std::cout << "Copy Data assignation called" << std::endl;
    if (this != &data) {
        this->boo = data.getBool();
        this->ch = data.getChar();
        this->nbr = data.getNbr();
        this->str = data.getStr();
    }
    return (*this);
}

Data::~Data(void)
{
	std::cout << "Destructor for Data called" << std::endl;
}

bool Data::getBool(void) const
{
	return this->boo;
}

char Data::getChar(void) const
{
	return this->ch;
}

int Data::getNbr(void) const
{
	return this->nbr;
}

std::string Data::getStr() const
{
	return this->str;
}

std::ostream &operator<<(std::ostream &out, Data const &data)
{
	out << " Bool | Char |       Number | String " << std::endl
		<< std::setw(5) << (data.getBool() ? "true" : "false") << " | "
		<< std::setw(4) << data.getChar() << " | "
		<< std::setw(12) << data.getNbr() << " | "
		 << data.getStr() << std::endl;
	return (out);
}
