#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog();
	Dog(std::string const type);
	Dog(const Dog& copy);
	Dog	&operator=(Dog const& dog);
	~Dog();

	void		makeSound(void) const;
};

#endif