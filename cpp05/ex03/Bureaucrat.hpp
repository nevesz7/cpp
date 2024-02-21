#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(Bureaucrat const& bureaucrat);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int const grade);
		void		increaseGrade();
		void		decreaseGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm &form);

		class GradeTooHighException : public std::exception
		{
			const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif