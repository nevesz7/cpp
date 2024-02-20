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
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat& operator=(Bureaucrat const& bureaucrat);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int const grade);
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm &form);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);

#endif