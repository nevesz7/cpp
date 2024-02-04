#include "Fixed.hpp"

// int main( void ) {
// Fixed a;
// Fixed const b( 10 );
// Fixed const c( 42.42f );
// Fixed const d( b );
// a = Fixed( 1234.4321f );
// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// return 0;
// }

int main(void)
{
	Fixed zero(0);
	Fixed ten(10);
	Fixed ft(42);
	Fixed ft_ft(42.42f);
	const Fixed fixed_ft(42);
	const Fixed fixed_ft_ft(42.42f);

	std::cout << "Comparison operators tests" << std::endl;
	std::cout << "ft = " << ft << " | ft_ft = " << ft_ft << std::endl;
	std::cout << "ft < ft_ft:  " << (ft < ft_ft ? "true" : "false") << std::endl;
	std::cout << "ft > ft_ft:  " << (ft > ft_ft ? "true" : "false") << std::endl;
	std::cout << "ft <= ft_ft: " << (ft <= ft_ft ? "true" : "false") << std::endl;
	std::cout << "ft >= ft_ft: " << (ft >= ft_ft ? "true" : "false") << std::endl;
	std::cout << "ft == ft_ft: " << (ft == ft_ft ? "true" : "false") << std::endl;
	std::cout << "ft != ft_ft: " << (ft != ft_ft ? "true" : "false") << std::endl;

	std::cout << std::endl << "Mathematical operators tests" << std::endl;
	std::cout << "ft = " << ft << " | ft_ft = " << ft_ft << std::endl;
	std::cout << "ft + 10 = " << ft + ten << std::endl;
	std::cout << "ft - 10 = " << ft - ten << std::endl;
	std::cout << "ft * 10 = " << ft * ten << std::endl;
	std::cout << "ft / 10 = " << ft / ten << std::endl << std::endl;

	std::cout << "ft_ft * 10 = " << ft_ft * ten << std::endl;
	std::cout << "ft_ft / 10 = " << ft_ft / ten << std::endl;
	std::cout << "ft_ft / 100 = " << ft_ft / (ten * ten) << std::endl << std::endl;

	std::cout << "ft * ft = " << ft * ft << std::endl;
	std::cout << "ft_ft + ft = " << ft_ft + ft << std::endl;
	std::cout << "ft_ft - ft = " << ft_ft - ft << std::endl;
	std::cout << "ft_ft / ft_ft = " << ft_ft / ft_ft << std::endl;
	std::cout << "ft_ft / ft = " << ft_ft / ft << std::endl;

	std::cout << std::endl << "min(ft, ft_ft) -> " << Fixed::min(ft, ft_ft) << std::endl;
	std::cout << "max(ft, ft_ft) -> " << Fixed::max(ft, ft_ft) << std::endl;
	std::cout << "min(const ft, const ft_ft) -> " << Fixed::min(fixed_ft, fixed_ft_ft) << std::endl;
	std::cout << "max(const ft, const ft_ft) -> " << Fixed::max(fixed_ft, fixed_ft_ft) << std::endl;

	std::cout << std::endl << "Increment and decrement tests" << std::endl;
	std::cout << ft << std::endl;
	std::cout << ++ft << std::endl;
	std::cout << ft << std::endl;
	std::cout << ft++ << std::endl;
	std::cout << ft << std::endl;
}
