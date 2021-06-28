#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack() {}
		MutantStack(MutantStack<T> const & other) { this->c = other.c; }
		~MutantStack()	{}
		MutantStack<T> & operator=(MutantStack<T> const & right)
		{
			if (this != &right)
			{
				this->c = right.c;
			}
			return *this;
		}

		iterator	begin();
		iterator	end();
};

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()	{ return (this->c.begin());	}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()	{ return (this->c.end());	}

#endif
