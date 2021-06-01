#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::srand(std::time(nullptr));
	ScavTrap	a;
	ScavTrap	b("Claptrappington");

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

	FragTrap	c;
	FragTrap	d("Claptrappington");

	c.takeDamage(35);
	c.takeDamage(35);
	c.takeDamage(35);
	c.takeDamage(35);
	c.takeDamage(35);
	std::cout << "* * *" << std::endl;
	c.beRepaired(35);
	c.beRepaired(35);
	c.beRepaired(35);
	c.beRepaired(35);
	std::cout << "* * *" << std::endl;
	d.rangedAttack("target_1");
	std::cout << "* * *" << std::endl;
	d.meleeAttack("target_2");
	std::cout << "* * *" << std::endl;
	d.rangedAttack("target_1");
	std::cout << "* * *" << std::endl;
	d.meleeAttack("target_2");
	std::cout << "* * *" << std::endl;
	d.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	d.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	d.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	d.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	d.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	d.vaulthunter_dot_exe("target_3");
	std::cout << "* * *" << std::endl;
	return 0;
}
