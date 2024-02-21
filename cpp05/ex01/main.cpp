#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "\t\t======= Creating forms =======" << std::endl << std::endl;
	Form	f1("Form 1", 10, 10), f2("Form 2", 50, 50), f3("Form 3", 100, 100);

	try 
	{	Form	f4("Form 4", 50, 0);}
	catch (std::exception const &e) {
        std::cerr << "Couldn't create form: " << e.what() << std::endl;
    }

	try 
	{	Form	f5("Form 5", 0, 50);}
	catch (std::exception const &e) {
        std::cerr << "Couldn't create form: " << e.what() << std::endl;
    }

	try 
	{	Form	f6("Form 6", 500, 50);}
	catch (std::exception const &e) {
        std::cerr << "Couldn't create form: " << e.what() << std::endl;
    }

	try 
	{	Form	f7("Form 7", 50, 500);}
	catch (std::exception const &e) {
        std::cerr << "Couldn't create form: " << e.what() << std::endl;
    }

	std::cout << std::endl << "\t\t======= Creating bureaucrats =======" << std::endl << std::endl;
	Bureaucrat b1("Bureaucrat 1", 99), b2("Bureaucrat 2", 42), b3("Bureaucrat 3", 1);

	std::cout << std::endl << "\t\t======= Trying to sign forms =======" << std::endl << std::endl;
	b1.signForm(f1);
	b2.signForm(f1);
	b3.signForm(f1);
	b1.signForm(f2);
	b2.signForm(f2);
	b3.signForm(f2);
	b1.signForm(f3);
	b2.signForm(f3);
	b3.signForm(f3);
}