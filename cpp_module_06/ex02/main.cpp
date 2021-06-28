#include <iostream>

#include "Base.hpp"

Base	*generate()
{
	int	num = std::rand() % 3;

	if (num == 0)
	{
		std::cout << "A generated" << std::endl;
		return new A;
	}
	else if (num == 1)
	{
		std::cout << "B generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return new C;
	}
}

void	identify_from_pointer(Base *p)
{
	if (nullptr != p)
	{
		if (nullptr != dynamic_cast<A *>(p))
			std::cout << "A" << std::endl;
		else if (nullptr != dynamic_cast<B *>(p))
			std::cout << "B" << std::endl;
		else if (nullptr != dynamic_cast<C *>(p))
			std::cout << "C" << std::endl;
		else
			std::cout << "pointer function: unknown class" << std::endl;
	}
}

void	identify_from_reference(Base &p)
{
	if (nullptr != dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (nullptr != dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (nullptr != dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "reference function: unknown class" << std::endl;
}

int	main()
{
	std::srand(std::time(0));

	std::cout << "generating pointer ..." << std::endl;
	Base	*temp_p = generate();
	std::cout << "identifying pointer => ";
	identify_from_pointer(temp_p);

	std::cout << "~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "generating reference ..." << std::endl;
	Base	&temp_r = *generate();
	std::cout << "identifying reference => ";
	identify_from_reference(temp_r);
	return 0;
}
