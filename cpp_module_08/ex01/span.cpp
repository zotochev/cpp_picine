#include "span.hpp"

Span::Span()
	: _n(0)
{}

Span::Span(unsigned int n)
	: _n(n)
{}

Span::Span(Span const & other)
	: _n(other.getN())
{
	_array = other._array;
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_array.size() < _n)
	{
		_array.push_back(number);
	}
	else
		throw std::exception();
}

int		Span::shortestSpan() const
{
	int		result;
	int		buf;

	if (_array.size() >= 2)
	{
		std::vector<int>	temp = _array;

		std::sort(temp.begin(), temp.end());
		result = *(temp.begin() + 1) - *temp.begin();
	
		for (std::vector<int>::iterator i = temp.begin() + 2; i != temp.end(); ++i)
		{
			buf = *i - *(i - 1);
			if (buf < result)
			{
				result = buf;
			}
		}
		temp.clear();
		return result;
	}
	else
		throw std::exception();
}

int		Span::longestSpan() const
{
	int		min;
	int		max;

	if (_array.size() >= 2)
	{
		min = *(std::min_element(_array.begin(), _array.end()));
		max = *(std::max_element(_array.begin(), _array.end()));

		return max - min;
	}
	else
		throw std::exception();
}

unsigned int	Span::getN() const		{ return _n; }

