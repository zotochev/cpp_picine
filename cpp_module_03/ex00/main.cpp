#include <iostream>

#include "FragTrap.hpp"

int main()
{
	std::srand(std::time(nullptr));
	FragTrap	a;
	FragTrap	b("Claptrappington");
	FragTrap	c(b);

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
	b.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	b.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	b.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	b.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	b.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	b.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	a = b;
	std::cout << "* * *" << std::endl;

	return 0;
}
