#include "mutantstack.hpp"

int	main()
{
	MutantStack<int>    mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "-----int---------" << std::endl;
	MutantStack<int>    mustack;
	mustack.push(1);
	mustack.push(3);
	mustack.push(5);
	mustack.push(7);
	mustack.push(9);
	mustack.push(8);
	mustack.push(6);
	mustack.push(4);
	mustack.push(2);
	mustack.push(0);
	std::cout << mustack.top() << std::endl;
	std::cout << *mustack.begin() << std::endl;
	std::cout << *mustack.end() << std::endl;
	std::cout << mustack.size() << std::endl;
	std::cout << "[";
	for (MutantStack<int>::iterator i = mustack.begin(); i != mustack.end(); ++i)
	{
		std::cout << *i << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "-----copy--------" << std::endl;

	MutantStack<int>    mustack_copy = mustack;
	std::cout << "[";
	for (MutantStack<int>::iterator i = mustack_copy.begin(); i != mustack_copy.end(); ++i)
	{
		std::cout << *i << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "-----copy-const--" << std::endl;

	MutantStack<int>    mustack_const(mustack);
	std::cout << "[";
	for (MutantStack<int>::iterator i = mustack_const.begin(); i != mustack_const.end(); ++i)
	{
		std::cout << *i << ", ";
	}
	std::cout << "]" << std::endl;

	std::cout << "-----string------" << std::endl;
	MutantStack<std::string>    mustack_s;
	mustack_s.push("one");
	mustack_s.push("two");
	mustack_s.push("three");
	mustack_s.push("four");
	mustack_s.push("five");
	mustack_s.push("six");
	mustack_s.push("seven");
	mustack_s.push("eight");
	mustack_s.push("nine");
	mustack_s.push("ten");
	std::cout << mustack.top() << std::endl;
	std::cout << *mustack.begin() << std::endl;
	std::cout << *mustack.end() << std::endl;
	std::cout << mustack.size() << std::endl;
	std::cout << "[";
	for (MutantStack<std::string>::iterator j = mustack_s.begin(); j != mustack_s.end(); ++j)
	{
		std::cout << *j << ", ";
	}
	std::cout << "]" << std::endl;
	return 0;
}
