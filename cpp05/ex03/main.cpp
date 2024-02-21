#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << std::endl << "\t\t======= Creating Intern and Bureaucrat =======" << std::endl;
	Intern	int1;
	Bureaucrat bur1("Bureaucrat 1", 1);

	std::cout << std::endl << "\t\t======= Creating Forms =======" << std::endl;
	AForm *form1 = int1.makeForm("presidential pardon", "Criminal");
	AForm *form2 = int1.makeForm("shrubbery creation", "trees");
	AForm *form3 = int1.makeForm("robotomy request", "Human");

	std::cout << std::endl << "\t\t======= Presidential Pardon Form ======-" << std::endl;
	if (form1)
	{
		bur1.signForm(*form1);
		bur1.executeForm(*form1);
	}

	std::cout << std::endl << "\t\t======= Shrubbery Request Form ========" << std::endl;
	if (form2)
	{
		bur1.signForm(*form2);
		bur1.executeForm(*form2);
	}

	std::cout << std::endl << "\t\t======= Robotomy Request Form ========" << std::endl;
	if (form3)
	{
		bur1.signForm(*form3);
		bur1.executeForm(*form3);
	}

	std::cout << std::endl << "\t\t======= Invalid Form ========" << std::endl;
	try 
	{
		AForm *form4 = int1.makeForm("who", "Doctor");
		(void)form4;
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	delete form1;
	delete form2;
	delete form3;
}