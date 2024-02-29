#include "Span.hpp"
#include "printContainer.hpp"
#include <iostream>

int main()
{
	Span sp1 = Span(5);
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	sp1.addNumber(2);
	try {
		std::cout << sp1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	sp1.addNumber(3);
	sp1.addNumber(5);
	sp1.addNumber(7);
	sp1.addNumber(11);

	try {
		sp1.addNumber(0);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl << "Vector 1: ";
	printContainer(sp1.getElements());
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest  span: " << sp1.longestSpan() << std::endl << std::endl;

	const int arr[] = {21, 3, 1, 8, 1, 34, 5, 13, 0, 2};
	const size_t arr_size = sizeof(arr) / sizeof(arr[0]);

	Span sp2(arr_size);
	sp2.addRange(arr, arr + arr_size);
	std::cout << std::endl << "Vector 2: ";
	printContainer(sp2.getElements());
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest  span: " << sp2.longestSpan() << std::endl << std::endl;


	Span sp3(10001);
	for (int i = 0; i < 10001; i++)
		sp3.addNumber(i);
	std::cout << std::endl << "Vector 2: ";
	// printContainer(sp3.getElements());
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest  span: " << sp3.longestSpan() << std::endl << std::endl;
}