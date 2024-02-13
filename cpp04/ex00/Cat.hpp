#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(std::string const type);
	Cat(const Cat& copy);
	Cat	&operator=(Cat const& cat);
	~Cat();

	void		makeSound(void) const;
};

#endif