#include "easyfind.hpp"
#include "printContainer.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>


int main()
{
	{
		std::vector<int> vector;
		vector.push_back(1);
	    vector.push_back(2);
    	vector.push_back(3);

		const std::vector<int> copyV = vector;
		std::cout << "Vector: ";
    	printContainer(vector);
		printContainer(copyV);

		try {
			std::vector<int>::iterator vectorIterator;
			int i = 5;
			std::cout << "Searching for member with value equal to " << i << std::endl;
			vectorIterator = ::easyfind(vector, i);
			std::cout << "Value was found inside vector" << std::endl;
		} catch (const std::runtime_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::deque<int> deque;
		deque.push_back(4);
		deque.push_back(5);
		deque.push_back(6);

		std::cout << "Deque: ";
    	printContainer(deque);

		try {
			std::deque<int>::iterator dequeIterator;
			int i = 5;
			std::cout << "Searching for member with value equal to " << i << std::endl;
			dequeIterator = ::easyfind(deque, i);
			std::cout << "Value was found inside deque" << std::endl;
		} catch (const std::runtime_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::list<int> list;
		list.push_back(7);
		list.push_back(8);
		list.push_back(9);

		std::cout << "List: ";
    	printContainer(list);

		try {
			std::list<int>::iterator listIterator;
			int i = 5;
			std::cout << "Searching for member with value equal to " << i << std::endl;
			listIterator = ::easyfind(list, i);
			std::cout << "Value was found inside list" << std::endl;
		} catch (const std::runtime_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}