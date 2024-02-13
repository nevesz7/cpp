#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
	std::string type;

	public:
	WrongAnimal();
	WrongAnimal(std::string const type);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal	&operator=(WrongAnimal const& wrongAnimal);
	~WrongAnimal();

	std::string		getType(void) const;
	void			setType(std::string type);
	void			makeSound(void) const;
};

#endif