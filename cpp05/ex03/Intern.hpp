#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define MAX_FORMS 3

class Intern
{
    private:
        AForm	*makeShrubberyCreationForm(const std::string &target);
        AForm	*makeRobotomyRequestForm(const std::string &target);
        AForm	*makePresidentialPardonForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &intern);
		~Intern();

		AForm	*makeForm(const std::string &name, const std::string &target);

		class FormNotFoundException : public std::exception {
            const char* what(void) const throw();
        };
};

#endif
