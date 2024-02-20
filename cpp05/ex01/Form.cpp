#include "Form.hpp"

Form::Form() : name("form x"), isSigned(false), requiredToSign(5), requiredToExecute(5)
{
	std::cout << "Default Form constructor called" << std::endl;
	return ;
}

Form::Form(std::string name, int requiredToSign, int requiredToExecute) : name(name), isSigned(false), requiredToSign(checkGrade(requiredToSign)), requiredToExecute(checkGrade(requiredToExecute))
{
	std::cout << "Parameter Form constructor called" << std::endl;
	return ;
}

Form::Form(const Form& copy) : name(copy.getName()), isSigned(copy.getSigned()), requiredToSign(checkGrade(copy.getRequiredToSign())), requiredToExecute(checkGrade(copy.getRequiredToExecute()))
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Form &Form::operator=(Form const &form)
{
	std::cout << "Form copy assignation called" << std::endl;
	if (this != &form)
	{
		const_cast<std::string&>(this->name) = form.getName();
		this->isSigned = form.getSigned();
		const_cast<int&>(this->requiredToSign) = checkGrade(form.getRequiredToSign());
		const_cast<int&>(this->requiredToExecute) = checkGrade(form.getRequiredToExecute());
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > (int)requiredToSign)
		throw Form::GradeTooLowException();
	if (isSigned)
		throw Form::AlreadySignedException();
	isSigned = true;
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

int	Form::checkGrade(int const grade) {
	if (grade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Form::GradeTooLowException();
	return grade;
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
			<< ", grade needed to sign " << form.getRequiredToSign()
			<< ", grade needed to execute " << form.getRequiredToExecute() << "." << std::endl;
	return (outputFile);
}