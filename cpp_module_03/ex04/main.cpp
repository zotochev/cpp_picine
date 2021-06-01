#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int	main()
{
	std::srand(std::time(NULL));
//	FragTrap	a("Stu Beef");
	SuperTrap	z("Sellina Lemon");

//	z.vaulthunter_dot_exe("target_T");
//	z.ninjaShoebox(a);
	z.rangedAttack("target_1");
	z.meleeAttack("target_1");
	return 0;
}
