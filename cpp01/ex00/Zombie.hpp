#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
	std::string	name;

	public:
	Zombie(void);
	~Zombie(void);
	void		announce(void);
	void		set_name(std::string input);
	std::string	get_name(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif