#include "iter.hpp"

int	main( void )
{
	std::cout << "\t============= Printing =============" << std::endl;
	char		letters[12] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f'};
	std::string	elements[4] = {"Earth", "Air", "Wind", "Water"};
	int			numbers[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	std::cout << "\t============= Char =============" << std::endl;
	::iter(letters, 12, printing<char>);
	std::cout << std::endl;
	std::cout << "\t============= String =============" << std::endl;
	::iter(elements, 4, printing<std::string>);
	std::cout << std::endl;
	std::cout << "\t============= Ints =============" << std::endl;
	::iter(numbers, 10, printing<int>);
	std::cout << std::endl;
	::iter(numbers, 10, count<int>);
	std::cout << std::endl << "\t============= After Count =============" << std::endl;
	::iter(numbers, 10, printing<int>);
	std::cout << std::endl;
}
