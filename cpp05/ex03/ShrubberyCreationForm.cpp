#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , target("Undefined")
{
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Shrubbery Creation Form target parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & copy) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = copy;
	std::cout << "Shrubbery Creation Form, copy constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &copy )
{
	std::cout << "Shrubbery Creation Form copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->target = copy.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignException();
	else if (this->getRequiredToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::string		fileName;
		std::ofstream	file;

		fileName = this->getTarget() + "_shrubbery";
		file.open(fileName.c_str());
		if (!file.is_open())
			return ;
		file << "		 *\n		***\n	   *****\n	  *******\n	 *********\n	***********\n	   |||||\n\n		 @\n		@@@\n	   @@@@@\n	  @@@@@@@\n	 @@@@@@@@@\n	@@@@@@@@@@@\n	   |||||\n\n		##\n	   ####\n	  ######\n 	 ########\n	##########\n	   ||||\n\n		  +\n		 +++ \n		+++++\n	   +++++++\n	  +++++++++\n	 +++++++++++\n	+++++++++++++\n		|||||\n\n		 ^\n		/|\\ \n	   / | \\ \n	  /  |  \\ \n	 /   |   \\ \n	/____|____\\ \n	   |||||\n\n	    &\n	   &&&\n	  &&&&&\n	 &&&&&&&\n	&&&&&&&&&\n	  |||||\n\n	    %%\n	   %%%%\n	  %%%%%%\n	 %%%%%%%%\n	%%%%%%%%%%\n	   ||||\n";
		file.close();
	}
}

const char* ShrubberyCreationForm::CreateFileException::what() const throw()
{
	return ("Something went wrong while creating the shrubbery");
}
