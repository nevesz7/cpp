#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const& copy);
		~PresidentialPardonForm();

		void		execute(Bureaucrat const &executor) const;
		std::string	getTarget() const;

		class CreateFileException: public std::exception {
				const char* what() const throw();
		};
};

#endif