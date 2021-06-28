#include <iostream>
#include "iter.hpp"

void	foo(int const & i)
{
	std::cout << i * i << std::endl;
}

void	bar(char const & c)
{
	if (c >= 65 && c <= 90)
		std::cout << static_cast<char>(c + 32) << std::endl;
	else if (c >= 97 && c <= 122)
		std::cout << static_cast<char>(c - 32) << std::endl;
	else
		std::cout << c << std::endl;
}

int main()
{
	int		a[] = { 1, 2, 3, 4, 5 };
	char	b[] = "Hello, World!";

	print_array(a, 5);
	iter(a, 5, foo);
	print_array(b, 13);
	iter(b, 13, bar);
	return 0;
}

