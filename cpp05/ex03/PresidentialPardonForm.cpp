#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , target("Undefined")
{
	std::cout << "Default Presidential Pardon Form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "Parameter Presidential Pardon Form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = copy;
	std::cout << "Copy Presidential Pardon Form constructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &copy )
{
	std::cout << "Presidential Pardon Form copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->target = copy.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignException();
	else if (this->getRequiredToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char* PresidentialPardonForm::CreateFileException::what() const throw()
{
	return ("Something went wrong with the pardon");
}
