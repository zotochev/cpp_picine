#include <iostream>

#include "Whatever.hpp"

int	main()
{
	int	a = 2;
	int	b = 3;

	std::cout << "original:	";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "after swap:	";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "* * *" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "original:	";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after swap:	";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "* * *" << std::endl;

	float	e = 2.23456f;
	float	f = 3.87654f;

	std::cout << "original:	";
	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap( e, f );
	std::cout << "after swap:	";
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << "* * *" << std::endl;
	return 0;
}
