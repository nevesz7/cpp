#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	WrongCat(std::string const type);
	WrongCat(const WrongCat& copy);
	WrongCat	&operator=(WrongCat const& wrongCat);
	~WrongCat();

	void		makeSound(void) const;
};

#endif