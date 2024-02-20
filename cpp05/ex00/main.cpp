#include "Bureaucrat.hpp"

int	main(void)
{
	{
		std::cout << "\n============ Santiago test ============" << std::endl;
		try {
			Bureaucrat	b1("Santiago", 1);
			std::cout << b1 << std::endl;
			
			std::cout << b1.getName() << " -> Decrease grade\t|\t";
			b1.decreaseGrade();
			std::cout << b1 << std::endl;

			std::cout << b1.getName() << " -> Decrease grade\t|\t";
			b1.decreaseGrade();
			std::cout << b1 << std::endl;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1 << std::endl;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1 << std::endl;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1 << std::endl;

			std::cout << b1.getName() << " -> Increase grade\t|\t";
			b1.increaseGrade();
			std::cout << b1 << std::endl;
		}
		catch(std::exception & e) {
		std::cout << "Grade out of range : " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n=============== Scully Test =============" << std::endl;
		try {
			Bureaucrat	b2("Scully", 150);
			std::cout << b2 << std::endl;

			std::cout << b2.getName() << " -> Increase grade\t|\t";
			b2.increaseGrade();
			std::cout << b2 << std::endl;

			std::cout << b2.getName() << " -> Increase grade\t|\t";
			b2.increaseGrade();
			std::cout << b2 << std::endl;
			
			std::cout << b2.getName() << " -> Decrease grade\t|\t";
			b2.decreaseGrade();
			std::cout << b2 << std::endl;

			std::cout << b2.getName() << " -> Decrease grade\t|\t";
			b2.decreaseGrade();
			std::cout << b2 << std::endl;
			
			std::cout << b2.getName() << " -> Decrease grade\t|\t";
			b2.decreaseGrade();
			std::cout << b2 << std::endl;

			std::cout << b2.getName() << " -> Increase grade\t|\t";
			b2.increaseGrade();
			std::cout << b2 << std::endl;
		}
		catch(std::exception & e) {
		std::cout << "Grade out of range : " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n============= Default Test ============" << std::endl;
		try {
			Bureaucrat	b99;
			std::cout << b99 << std::endl;

			for (int i = 0; i < 150; i++)
			{
				std::cout << b99.getName() << " -> Increase grade\t|\t";
				b99.increaseGrade();
				std::cout << b99 << std::endl;
			}
		}
		catch(std::exception & e) {
		std::cout << "Grade out of range : " << e.what() << std::endl;
		}
	}
	return (0);
}