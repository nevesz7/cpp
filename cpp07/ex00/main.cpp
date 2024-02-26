#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

	bool t = true;
	bool f = false;
	std::cout << "t = " << t << ", f = " << f << std::endl;
	std::cout << "t = " << (t ? "true" : "false") << ", f = " << (f ? "true" : "false") << std::endl << std::endl;
	::swap(t, f);
	std::cout << "t = " << (t ? "true" : "false") << ", f = " << (f ? "true" : "false") << std::endl;
	std::cout << "min( t, f ) = " << (::min( t, f ) ? "true" : "false") << std::endl;
	std::cout << "max( t, f ) = " << (::max( t, f ) ? "true" : "false") << std::endl;

	return (0);
}