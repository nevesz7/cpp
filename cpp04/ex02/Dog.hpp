#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain	*brain;

	public:
	Dog();
	Dog(std::string const type);
	Dog(const Dog& copy);
	Dog	&operator=(Dog const& dog);
	~Dog();

	void		makeSound(void) const;
	Brain*		getBrain(void) const;
	std::string	getIdea(int index) const;
};

#endif