#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			requiredToSign;
		int const			requiredToExecute;

	public:
		Form();
		Form(const Form &copy);
		Form(std::string name, int requiredToSign, int requiredToExecute);
		Form &operator=(const Form &form);
		virtual ~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getRequiredToSign() const;
		int			getRequiredToExecute() const;
		void		beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
				virtual const char* what(void) const throw();
		};
		class AlreadySignedException: public std::exception {
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &output, Form const &form);

#endif
