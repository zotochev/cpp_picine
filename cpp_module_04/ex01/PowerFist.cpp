#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50)
{
	setAttackSound("* pschhh... SBAM! *");
	std::cout << "Power Fist created" << std::endl;
}

PowerFist::~PowerFist()
{
	std::cout << "Power Fist destructed" << std::endl;
}

void	PowerFist::attack() const
{
	AWeapon::attack();
}
