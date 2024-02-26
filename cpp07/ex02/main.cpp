#include "Array.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	std::cout << "\n-------------- Other tests ---------------" << std::endl;

	std::cout << "Default Constructor" << std::endl;
	Array<int> intArray;
	Array<std::string> stringArray;

	std::cout << "\tintArray.size() = " << intArray.size() << std::endl;
	std::cout << "\tstringArray.size() = " << stringArray.size() << std::endl << std::endl;

	std::cout << "\nInt passed to constructor" << std::endl;
	Array<int> intArray1(7);

	std::cout << "\t[";
	for (unsigned int i = 0; i < intArray1.size(); i++)
	{
		intArray1[i] = i;
		std::cout << intArray1[i];
		if ((i + 1) != intArray1.size())
			std::cout << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "\tintArray1.size() = " << intArray1.size() << std::endl;

	std::cout << "\nArray of strings" << std::endl;
	Array<std::string> stringArray1(3);

	stringArray1[0] = "foo";
	stringArray1[1] = "bar";
	stringArray1[2] = "banana";
	std::cout << "\t[";
	for (unsigned int i = 0; i < stringArray1.size(); i++)
	{
		std::cout << stringArray1[i];
		if ((i + 1) != stringArray1.size())
			std::cout << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "\tstringArray1.size() = " << stringArray1.size() << std::endl;
	
	std::cout << "\nErrors tests" << std::endl;
	std::cout << "\tnegative value index" << std::endl ;
	try
	{
		intArray1[-1] = 42;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\tout of range value index" << std::endl;
	try
	{
		intArray[55] = 42;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}