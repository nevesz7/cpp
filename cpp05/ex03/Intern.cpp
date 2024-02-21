#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(Intern const &intern)
{
    (void)intern;
    return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string forms[MAX_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

    AForm *(Intern::*makers[MAX_FORMS])(std::string const &target) = {
			&Intern::makeShrubberyCreationForm,
        	&Intern::makeRobotomyRequestForm,
        	&Intern::makePresidentialPardonForm
		};
	
	for (size_t i = 0; i < MAX_FORMS; i++) {
        if (name == forms[i]) {
            std::cout << "Intern creates " << name << ", with '" << target
                      << "' as target" << std::endl;
            return ((this->*makers[i])(target));
        }
    }
	throw FormNotFoundException();
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

char const *Intern::FormNotFoundException::what(void) const throw()
{
    return ("Requested form does not exist");
}