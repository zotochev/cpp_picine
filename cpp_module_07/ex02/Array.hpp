#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & other);
		~Array();

		Array &		operator= (Array const & right);
		T &			operator[](int idx);
		const T &	operator[](int idx) const;

		int	size() const;

		class indexOutOfRange : public std::exception
		{
			public:
				virtual const char * what() const throw() { return "Exception: list index out of range."; }
		};

	private:
		T		*_array;
		int		_size;
};

template <typename T>
std::ostream & operator<<(std::ostream & os, Array<T> const & obj)
{
	os << "[";
	if (obj.size() > 0)
	{
		for (int i = 0; i < obj.size(); i++)
		{
			os << obj[i];
			if (i + 1 != obj.size())
				os << ", ";
		}
	}
	os << "]";
	os << std::endl;
	return os;
}

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T [n]), _size(n)
{}

template <typename T>
Array<T>::Array(Array<T> const & other)
	: _array(new T [other.size()])
	, _size(other.size())
{
	for (int i = 0; i < _size; i++)
		_array[i] = other[i];
}

template <typename T>
Array<T>::~Array()
{
	if (_size > 0)
		delete [] _array;
}

template <typename T>
int	Array<T>::size() const
{
	return _size;
}

template <typename T>
T & Array<T>::operator[](int idx)
{
	if (idx >= 0 && idx < _size && _size != 0)
		return _array[idx];
	else
		throw indexOutOfRange();
}

template <typename T>
const T & Array<T>::operator[](int idx) const
{
	if (idx >= 0 && idx < _size && _size != 0)
		return _array[idx];
	else
		throw indexOutOfRange();
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & right)
{
	if (this != &right)
	{
		if (nullptr != _array)
			delete [] _array;
		_array = new T [right.size()];
		_size = right.size();
		for (int i = 0; i < _size; i++)
			_array[i] = right._array[i];
	}
	return *this;
}

#endif
