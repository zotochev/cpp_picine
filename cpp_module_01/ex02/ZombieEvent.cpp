#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(const std::string& type) : type(type)
{}

ZombieEvent::~ZombieEvent()
{}

void ZombieEvent::setZombieType(const std::string& type_)
{
	this->type = type_;
}

Zombie*	ZombieEvent::newZombie(const std::string& name)
{
	return new Zombie(name, this->type);
}

Zombie*	ZombieEvent::randomChump()
{
	std::string	names_list[] = {
			"Ash Williams",
			"Billy Butcherson",
			"Bub",
			"Dr. Hill",
			"Detective Roger Mortis",
			"Ed",
			"Eddie",
			"Evil Ash",
			"Fido",
			"Frankenstein",
			"Ghoulia Yelps",
			"Jason Todd",
			"Jason Voorhees",
			"Judge Hopkins",
			"Julie"
	};
	std::string chosen_name;

	std::srand(time(nullptr));
	chosen_name = names_list[std::rand() % 15];
	return newZombie(chosen_name);
}