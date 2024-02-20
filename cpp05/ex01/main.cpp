#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "\n----------------------------------------" << std::endl;
	try {
		std::cout << "Try form with 1 signed grade and 2 exec grade..." << std::endl;
		Form	F1("Form 1", 1, 2);
		std::cout << F1 << std::endl;
	} 
	catch(std::exception & e) { std::cout << "Error: " << e.what() << std::endl; }

	std::cout << "\n----------------------------------------" << std::endl;
	try {
		std::cout << "Try form with 0 signed grade and 2 exec grade..." << std::endl;
		Form	F2("Form 2", 0, 2);
		std::cout << F2 << std::endl;
	} 
	catch(std::exception & e) { std::cout << "Error: " << e.what() << std::endl; }
	
	std::cout << "\n----------------------------------------" << std::endl;
	try {
		std::cout << "Try form with 151 signed grade and 2 exec grade..." << std::endl;
		Form	F3("Form 3", 151, 2);
		std::cout << F3 << std::endl;
	} 
	catch(std::exception & e) { std::cout << "Error: " << e.what() << std::endl; }
	
	std::cout << "\n----------------------------------------" << std::endl;
	try {
		std::cout << "Try form with 1 signed grade and 0 exec grade..." << std::endl;
		Form	F4("Form 4", 1, 0);
		std::cout << F4 << std::endl;
	} 
	catch(std::exception & e) {	std::cout << "Error: " << e.what() << std::endl; }
	
	std::cout << "\n----------------------------------------" << std::endl;
	try {
		std::cout << "Try form with 1 signed grade and 151 exec grade..." << std::endl;
		Form	F5("Form 5", 1, 151);
		std::cout << F5 << std::endl;
	} 
	catch(std::exception & e) {	std::cout << "Error: " << e.what() << std::endl; }

	std::cout << "\n\n----------------------------------------" << std::endl;
	try {
		Bureaucrat	Bcrat1("Jeffords", 1);
		std::cout << Bcrat1 << std::endl;
		std::cout << "Try new form with 1 signed grade and 1 exec grade..." << std::endl;
		Form	F6("Form 6", 1, 1);
		std::cout << F6 << std::endl;
		std::cout << "Try to sign" << std::endl;
		Bcrat1.signForm(F6);
		std::cout << "Update of " << F6 << std::endl;
		std::cout << "Try to sign" << std::endl;
		Bcrat1.signForm(F6);
		std::cout << "Update of " << F6 << std::endl;
	} 
	catch(std::exception & e) {	std::cout << "Error: " << e.what() << std::endl; }
	
	std::cout << "\n----------------------------------------" << std::endl;
	try {
		Bureaucrat	Bcrat2("Holt", 3);
		std::cout << Bcrat2 << std::endl;
		std::cout << "Try new form with 1 signed grade and 1 exec grade..." << std::endl;
		Form	F7("Form 7", 1, 1);
		std::cout << F7 << std::endl;
		std::cout << "Try to sign" << std::endl;
		Bcrat2.signForm(F7);
		std::cout << "Update of " << F7 << std::endl;
		std::cout << Bcrat2.getName() << " -> Increment grade" << std::endl;
		Bcrat2.increaseGrade();
		std::cout << Bcrat2 << std::endl;
		std::cout << "Try to sign" << std::endl;
		Bcrat2.signForm(F7);
		std::cout << "Update of " << F7 << std::endl;
		Bcrat2.increaseGrade();
		std::cout << Bcrat2.getName() << " -> Increment grade" << std::endl;
		std::cout << Bcrat2 << std::endl;
		Bcrat2.signForm(F7);
		std::cout << "Update of " << F7 << std::endl;
	} 
	catch(std::exception & e) {	std::cout << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	return (0);
}