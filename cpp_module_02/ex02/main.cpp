#include <iostream>
#include "Fixed.hpp"

int	main() {
	Fixed			a;
	Fixed	const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed			z(5);
	Fixed			y(10);

	std::cout << (z / 0) << std::endl;
	return 0;
}
