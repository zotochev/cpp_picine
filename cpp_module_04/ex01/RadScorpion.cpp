#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
	: Enemy(80, "RadScorpion")
{
	std::cout << getPrettyName() << " * click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << getPrettyName() << " * SPROTCH *" << std::endl;
}

void	RadScorpion::takeDamage(int damage)
{
	if (getHP() > 0 && damage >= 0)
	{
		if (damage > getHP())
			setHP(0);
		else
			setHP(getHP() - damage);
//		std::cout	<< getPrettyName() << " got "
//					<< damage << " points of damage"
//					<< std::endl;
	}
}
