#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

template <typename T>
typename T::iterator	easyfind(T t, int num)
{
	typename T::iterator	it;
	
	if (t.end() == (it = std::find(t.begin(), t.end(), num)))
	{
		throw std::exception();
	}
	else
	{
		return it;
	}
}

#endif
