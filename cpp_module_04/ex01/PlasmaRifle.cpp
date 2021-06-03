#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
	: AWeapon("Plasma Rifle", 5, 21)
{
	setAttackSound("* piouuu piouuu piouuu *");
	std::cout << "Plasma Rifle created" << std::endl;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << "Plasma Rifle destructed" << std::endl;
}

void	PlasmaRifle::attack() const
{
	AWeapon::attack();
}
