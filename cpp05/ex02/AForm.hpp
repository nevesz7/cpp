#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			requiredToSign;
		int const			requiredToExecute;
		int					checkGrade(int const grade);

	public:
		AForm();
		AForm(const Form &copy);
		AForm(std::string name, int requiredToSign, int requiredToExecute);
		AForm &operator=(const Form &form);
		virtual ~AForm();

		std::string		getName() const;
		bool			getSigned() const;
		int				getRequiredToSign() const;
		int				getRequiredToExecute() const;
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const& executor) const = 0;
		void			checkExecute(Bureaucrat const& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class AlreadySignedException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};

		class FormNotSignException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		
		class NoPermissionException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &output, AForm const &form);

#endif