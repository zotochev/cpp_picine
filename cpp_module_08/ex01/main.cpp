#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <string_view>
#include "span.hpp"

int	main()
{
	std::srand(time(nullptr));
	Span sp = Span(5);

	sp.addNumber(-5);
	sp.addNumber(3);
	sp.addNumber(-17);
	sp.addNumber(9);
	sp.addNumber(-11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----10000 test----" << std::endl;

	std::cout << "--random- test 1--" << std::endl;
	Span sp_big = Span(10000);
	for (int i = 0; i < 10000; ++i)
	{
		sp_big.addNumber(std::rand());
	}
	std::cout << sp_big.shortestSpan() << std::endl;
	std::cout << sp_big.longestSpan() << std::endl;


	std::cout << "--simple- test 2--" << std::endl;
	Span sp_big_2 = Span(10000);
	for (int i = 0; i < 10000; ++i)
	{
		if (i == 100)
			sp_big_2.addNumber(100);
		else
			sp_big_2.addNumber(10);
	}
	std::cout << sp_big_2.shortestSpan() << std::endl;
	std::cout << sp_big_2.longestSpan() << std::endl;
	return 0;
}
