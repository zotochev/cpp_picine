#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main()
{
	FragTrap	b("Blanche Dwight");
	ScavTrap	c("Charlotte Russe");
	NinjaTrap	z("Norman Conquest");

	z.ninjaShoebox(b);
	z.ninjaShoebox(c);
	return 0;
}
