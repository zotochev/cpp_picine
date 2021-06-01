#include "ZombieHorde.hpp"
#include <iostream>

int	main()
{
	std::srand(std::time(nullptr));

	ZombieHorde	horde_default(3);
	std::cout << "~~~~~~~~~~~" << std::endl;
	ZombieHorde	horde_smoker(3, "smoker");
	std::cout << "~~~~~~~~~~~" << std::endl;
	horde_smoker.announce();
	std::cout << "~~~~~~~~~~~" << std::endl;
	return 0;
}