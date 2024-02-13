#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
	std::string type;

	public:
	Animal();
	Animal(std::string const type);
	Animal(const Animal& copy);
	Animal	&operator=(Animal const& animal);
	virtual ~Animal();

	std::string		getType(void) const;
	void			setType(std::string type);
	virtual void	makeSound(void) const;
};

#endif