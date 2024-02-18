#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain	*brain;

	public:
	Cat();
	Cat(std::string const type);
	Cat(const Cat& copy);
	Cat	&operator=(Cat const& cat);
	~Cat();

	void		makeSound(void) const;
	Brain*		getBrain(void) const;
	std::string	getIdea(int index) const;
};

#endif