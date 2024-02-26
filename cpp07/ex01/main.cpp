#include "iter.hpp"

int	main( void )
{
	std::cout << "\t============= Printing =============" << std::endl;
	char		letters[12] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f'};
	std::string	elements[4] = {"Earth", "Air", "Wind", "Water"};
	int			numbers[11] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

	std::cout << "\t============= Char =============" << std::endl;
	::iter(letters, 12, printing<char>);
	std::cout << std::endl;
	std::cout << "\t============= String =============" << std::endl;
	::iter(elements, 4, printing<std::string>);
	std::cout << std::endl;
	std::cout << "\t============= Ints =============" << std::endl;
	::iter(numbers, 11, printing<int>);
	std::cout << std::endl;
	::iter(numbers, 11, fibonacci<int>);
	std::cout << std::endl << "\t============= After Fibonacci =============" << std::endl;
	::iter(numbers, 11, printing<int>);
	std::cout << std::endl;
}