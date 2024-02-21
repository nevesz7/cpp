#include "Bureaucrat.hpp"

void insertTestHeader(std::string header){
	std::cout << std::endl << "\t============ " << header << " test ============" << std::endl << std::endl;
}

int	main(void)
{
	{
		insertTestHeader("Santiago");
		try {
			Bureaucrat	b1("Santiago", 1);
			std::cout << b1 << std::endl;
			
			std::cout << b1.getName() << " -> Decrease grade\t|\t";
			b1.decreaseGrade();
			std::cout << b1;

			std::cout << b1.getName() << " -> Decrease grade\t|\t";
			b1.decreaseGrade();
			std::cout << b1;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1;
		}
		catch(std::exception & e) {
			std::cout << std::endl << "Grade out of range : " << e.what() << std::endl;
		}
	}
	{
		insertTestHeader("Scully");
		try {
			Bureaucrat	b2("Scully", 150);
			std::cout << b2 << std::endl;

			std::cout << b2.getName() << " -> Increase grade\t|\t";
			b2.increaseGrade();
			std::cout << b2;

			std::cout << b2.getName() << " -> Increase grade\t|\t";
			b2.increaseGrade();
			std::cout << b2;
			
			std::cout << b2.getName() << " -> Decrease grade\t|\t";
			b2.decreaseGrade();
			std::cout << b2;

			std::cout << b2.getName() << " -> Decrease grade\t|\t";
			b2.decreaseGrade();
			std::cout << b2;
			
			std::cout << b2.getName() << " -> Decrease grade\t|\t";
			b2.decreaseGrade();
			std::cout << b2;

			std::cout << b2.getName() << " -> Increase grade\t|\t";
			b2.increaseGrade();
			std::cout << b2;
		}
		catch(std::exception & e) {
		std::cout << std::endl << "Grade out of range : " << e.what() << std::endl;
		}
	}
	{
		insertTestHeader("Default");
		try {
			Bureaucrat	b99;
			std::cout << b99 << std::endl;

			for (int i = 0; i < 150; i++)
			{
				std::cout << b99.getName() << " -> Increase grade\t|\t";
				b99.increaseGrade();
				std::cout << b99;
			}
		}
		catch(std::exception & e) {
		std::cout << std::endl << "Grade out of range : " << e.what() << std::endl;
		}
	}
	return (0);
}