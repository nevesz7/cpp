#include "header.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	usleep(424242);
	unsigned seed = time(0);
	srand(seed);
	int random = rand() % 4;

    switch (random) {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (new Base);
}

void identify(Base *p) {
    std::cout << (dynamic_cast<A*>(p) ? "This pointer is an instance of Class A." :
            	dynamic_cast<B*>(p) ? "This pointer is an instance of Class B." :
                dynamic_cast<C*>(p) ? "This pointer is an instance of Class C." :
                "This pointer is not an instance of A, B or C classes.") << std::endl;
}

void identify(Base &p) {
    try {
        A a = dynamic_cast<A &>(p);
        std::cout << "This reference point to an instance of Class A." << std::endl;
		return ;
    } catch (std::exception const &) {}
   	try {
        B b = dynamic_cast<B &>(p);
        std::cout << "This reference point to an instance of Class B." << std::endl;
		return ;
    } catch (std::exception const &) {}
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "This reference point to an instance of Class C." << std::endl;
		return ;
	} catch (std::exception const &) {}
	std::cerr << "This reference does not point to an instance of A, B or C classes." << std::endl;
}
