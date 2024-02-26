#include "header.hpp"

int	main(void) {
	Base	*base;

	base = new A;
	std::cout << std::endl;
	identify(base);
	identify(*base);
	delete base;

	base = new B;
	std::cout << std::endl;
	identify(base);
	identify(*base);
	delete base;

	base = new C;
	std::cout << std::endl;
	identify(base);
	identify(*base);
	delete base;

	base = new Base;
	std::cout << std::endl;
	identify(base);
	identify(*base);
	delete base;

	std::cout << std::endl << "\t===================================" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		base = generate();
		std::cout << std::endl;
		identify(base);
		identify(*base);
		delete base;
	}
}