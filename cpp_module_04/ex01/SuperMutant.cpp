#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
	: Enemy(170, "Super Mutant")
{
	std::cout << getPrettyName() << " Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << getPrettyName() << " Aaargh..." << std::endl;
}

void	SuperMutant::takeDamage(int damage)
{
	if (getHP() > 0 && damage >= 0)
	{
		if (damage > 3)
			damage -= 3;
		else
			damage = 0;
		if (damage > getHP())
		{
			setHP(0);
		}
		else
		{
			setHP(getHP() - damage);
		}
//		std::cout	<< getPrettyName() << " got "
//					<< damage << " points of damage"
//					<< std::endl;
	}
}
