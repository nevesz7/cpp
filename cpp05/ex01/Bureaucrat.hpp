#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include "Form.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Form;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		virtual ~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int const grade);
		void		increaseGrade();
		void		decreaseGrade();
		void		signForm(Form &form);

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
