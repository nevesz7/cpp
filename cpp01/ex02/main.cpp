#include <iostream>

int main ()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of ptr: " << &ptr << std::endl;
	std::cout << "Address of ref: " << &ref << std::endl;
	std::cout << std::endl;
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of ptr: " << ptr << std::endl;
	std::cout << "Value of ref: " << ref << std::endl;
}
