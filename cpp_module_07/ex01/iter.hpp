#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *a, size_t length, void (*f)(T const & ))
{
	size_t	count;

	count = 0;
	while (count < length)
	{
		f(a[count]);
		count++;
	}
}

template <typename T>
void	print_array(T *a, size_t length)
{
	size_t	count;

	count = 0;
	while (count < length)
	{
		std::cout << a[count];
		count++;
	}
	std::cout << std::endl;
}

#endif
