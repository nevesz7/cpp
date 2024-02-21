#include "Form.hpp"

Form::Form() : name("form x"), isSigned(false), requiredToSign(MIN_GRADE), requiredToExecute(MIN_GRADE)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int requiredToSign, int requiredToExecute) : name(name), isSigned(false), requiredToSign(requiredToSign), requiredToExecute(requiredToExecute)
{
	std::cout << "Parameter Form constructor called" << std::endl;
	if (this->requiredToSign > MIN_GRADE || this->requiredToExecute > MIN_GRADE)
        throw GradeTooLowException();
    if (this->requiredToSign < MAX_GRADE || this->requiredToExecute < MAX_GRADE)
        throw GradeTooHighException();
}

Form::Form(const Form& copy) : name(copy.getName()), isSigned(copy.getSigned()), requiredToSign(copy.getRequiredToSign()), requiredToExecute(copy.getRequiredToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

Form &Form::operator=(Form const &form)
{
	std::cout << "Form copy assignation called" << std::endl;
	if (this != &form)
	{
		const_cast<std::string&>(this->name) = form.getName();
		this->isSigned = form.getSigned();
		const_cast<int&>(this->requiredToSign) = form.getRequiredToSign();
		const_cast<int&>(this->requiredToExecute) = form.getRequiredToExecute();
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > (int)requiredToSign)
		throw Form::GradeTooLowException();
	if (this->isSigned)
		throw Form::AlreadySignedException();
	this->isSigned = true;
}

bool	Form::getSigned(void) const
{
	return (this->isSigned);
}

int	Form::getRequiredToSign(void) const
{
	return(this->requiredToSign);
}

int	Form::getRequiredToExecute(void) const
{
	return(this->requiredToExecute);
}

std::string Form::getName(void) const
{
	return (this->name);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High Exception");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low Exception");
}

const char* Form::AlreadySignedException::what() const throw() {
	return ("Already Signed Exception");
}

std::ostream &operator<<(std::ostream &outputFile, Form const &form)
{
	outputFile	<< "Form: " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed")
			<< ", grade needed to sign: " << form.getRequiredToSign()
			<< ", grade needed to execute: " << form.getRequiredToExecute() << "." << std::endl;
	return (outputFile);
}