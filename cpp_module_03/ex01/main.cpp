#include <iostream>

#include "ScavTrap.hpp"

int main()
{
	std::srand(std::time(nullptr));
	ScavTrap	a;
	ScavTrap	b("Claptrappington");
	ScavTrap	c(b);

	a.takeDamage(35);
	a.takeDamage(35);
	a.takeDamage(35);
	a.takeDamage(35);
	a.takeDamage(35);
	std::cout << "* * *" << std::endl;
	a.beRepaired(35);
	a.beRepaired(35);
	a.beRepaired(35);
	a.beRepaired(35);
	std::cout << "* * *" << std::endl;
	b.rangedAttack("target_1");
	std::cout << "* * *" << std::endl;
	b.meleeAttack("target_2");
	std::cout << "* * *" << std::endl;
	b.rangedAttack("target_1");
	std::cout << "* * *" << std::endl;
	b.meleeAttack("target_2");
	std::cout << "* * *" << std::endl;
	b.challengeNewcomer("target_3");
	std::cout << "* * *" << std::endl;
	b.challengeNewcomer("target_3");
	std::cout << "* * *" << std::endl;
	b.challengeNewcomer("target_3");
	std::cout << "* * *" << std::endl;
	b.challengeNewcomer("target_3");
	std::cout << "* * *" << std::endl;
	b.challengeNewcomer("target_3");
	std::cout << "* * *" << std::endl;
	b.challengeNewcomer("target_3");
	std::cout << "* * *" << std::endl;
	a = b;
	std::cout << "* * *" << std::endl;

	return 0;
}
