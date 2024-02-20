#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &brain);
	virtual ~Intern();
private:
};

#endif
