#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

#include <functional>
#include <string_view>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const & other);
		~Span();

		Span & operator=(Span const & right);

		void	addNumber(int number);

		int		shortestSpan() const;
		int		longestSpan() const;

		unsigned int	getN() const;

	private:
		Span();

		std::vector<int>	_array;
		unsigned int		_n;
};

#endif
