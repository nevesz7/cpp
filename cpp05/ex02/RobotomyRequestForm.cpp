#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) , target("Undefined")
{
	std::cout << "Default Robotomy Request Form constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "Parameter Robotomy Request Form constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & copy) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = copy;
	std::cout << "Copy Robotomy Request Form constructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &copy )
{
	std::cout << "Robotomy Request Form copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->target = copy.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignException();
	else if (this->getRequiredToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "* drilling noises *" << std::endl;
		usleep(500000);
		std::srand(std::time(0));
		if ((int)std::rand() % 2 != 0)
		{
			std::cout << this->target << " has been robotomized successfully." << std::endl;
		}
		else
		{
			std::cout << this->target << " robotomization failed." << std::endl;
		}
	}
}

const char* RobotomyRequestForm::CreateFileException::what() const throw()
{
	return ("Something went wrong while doing the robotomization");
}
