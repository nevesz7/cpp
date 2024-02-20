#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Peralta"), grade(100)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : name(name)
{
	std::cout << "Parameter Bureaucrat constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat copy assignation called" << std::endl;
	if (this != &bureaucrat)
	{
		const_cast<std::string&>(this->name) = bureaucrat.getName();
		this->grade = bureaucrat.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

void	Bureaucrat::setGrade(int const grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::increaseGrade(void)
{
	if (this->grade == MAX_GRADE) { throw GradeTooHighException (); }
	this->grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->grade == MIN_GRADE) { throw GradeTooLowException (); }
	this->grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &bureaucrat)
{
	outputFile	<< bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (outputFile);
}
