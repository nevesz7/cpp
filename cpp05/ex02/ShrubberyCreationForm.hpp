#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target );
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const& copy);
		~ShrubberyCreationForm();

		void		execute(Bureaucrat const &executor) const;
		std::string	getTarget() const;

		class CreateFileException: public std::exception {
				virtual const char* what() const throw();
		};
};

#endif