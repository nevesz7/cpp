#include "AForm.hpp"

AForm::AForm() : name("form x"), isSigned(false), requiredToSign(5), requiredToExecute(5)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int requiredToSign, int requiredToExecute) : name(name), isSigned(false), requiredToSign(checkGrade(requiredToSign)), requiredToExecute(checkGrade(requiredToExecute))
{
	std::cout << "Parameter AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : name(copy.getName()), isSigned(copy.getSigned()), requiredToSign(checkGrade(copy.getRequiredToSign())), requiredToExecute(checkGrade(copy.getRequiredToExecute()))
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}

AForm &AForm::operator=(AForm const &form)
{
	std::cout << "AForm copy assignation called" << std::endl;
	if (this != &form)
	{
		const_cast<std::string&>(this->name) = form.getName();
		this->isSigned = form.getSigned();
		const_cast<int&>(this->requiredToSign) = checkGrade(form.getRequiredToSign());
		const_cast<int&>(this->requiredToExecute) = checkGrade(form.getRequiredToExecute());
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > (int)requiredToSign)
		throw AForm::GradeTooLowException();
	if (isSigned)
		throw AForm::AlreadySignedException();
	isSigned = true;
}

bool	AForm::getSigned(void) const
{
	return (this->isSigned);
}

int	AForm::getRequiredToSign(void) const
{
	return(this->requiredToSign);
}

int	AForm::getRequiredToExecute(void) const
{
	return(this->requiredToExecute);
}

std::string AForm::getName(void) const
{
	return (this->name);
}

int	AForm::checkGrade(int const grade) {
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	return grade;
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out	<< "Form: " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed")
			<< ", grade needed to sign " << form.getRequiredToSign()
			<< ", grade needed to execute " << form.getRequiredToExecute() << "." << std::endl;
	return (out);
}

void	AForm::checkExecute(Bureaucrat const& bureaucat)
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignException();
	if (bureaucat.getGrade() > this->getRequiredToExecute())
		throw AForm::NoPermissionException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High Exception");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low Exception");
}

const char* AForm::AlreadySignedException::what() const throw() {
	return ("Already Signed Exception");
}

const char* AForm::FormNotSignException::what() const throw() {
	return ("There Is No Signature Exception");
}

const char* AForm::NoPermissionException::what() const throw() {
	return ("Executor Doesn't Have Permission Exception");
}
