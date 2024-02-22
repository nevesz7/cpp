#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::cout << "\t\t======== Creating Bureaucrats and Forms ========" << std::endl << std::endl;
	Bureaucrat president("President", 150), robotomizer("Robotomizer", 150), shrubbery("Shrubbery", 150);
	PresidentialPardonForm pardonFormulary("Criminal");
	RobotomyRequestForm robotomyFormulary("Human");
	ShrubberyCreationForm shruFormulary("trees");

	std::cout << std::endl << "\t\t======== Presidential Pardon Form ========" << std::endl << std::endl;

	president.executeForm(pardonFormulary);
	president.signForm(pardonFormulary);
	president.setGrade(1);
	std::cout << "increasing grade to be able to sign form" << std::endl;
	president.signForm(pardonFormulary);
	president.signForm(pardonFormulary);
	president.executeForm(pardonFormulary);

	std::cout << std::endl << "\t\t======== Shrubbery Request Form ========" << std::endl << std::endl;

	shrubbery.executeForm(shruFormulary);
	shrubbery.signForm(shruFormulary);
	shrubbery.setGrade(1);
	std::cout << "increasing grade to be able to sign form" << std::endl;
	shrubbery.signForm(shruFormulary);
	shrubbery.signForm(shruFormulary);
	shrubbery.executeForm(shruFormulary);

	std::cout << std::endl << "\t\t======== Robotomy Request Form ========" << std::endl << std::endl;

	robotomizer.executeForm(robotomyFormulary);
	robotomizer.signForm(robotomyFormulary);
	robotomizer.setGrade(1);
	std::cout << "increasing grade to be able to sign form" << std::endl;
	robotomizer.signForm(robotomyFormulary);
	robotomizer.signForm(robotomyFormulary);
	robotomizer.executeForm(robotomyFormulary);

	std::cout << std::endl;
}
