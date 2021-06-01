#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(unsigned N, const std::string& type) : N(N), type(type)
{
	this->horde = new Zombie*[N];

	for (unsigned i = 0; i < N; i++)
		this->horde[i] = this->randomChump();
}

ZombieHorde::~ZombieHorde()
{
	for (unsigned i = 0; i < N; i++)
		delete this->horde[i];
	delete [] this->horde;
	std::cout << "Zombie horde type of " << this->type << " has been destroyed" << std::endl;
}

Zombie	*ZombieHorde::randomChump()
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

	chosen_name = names_list[std::rand() % 15];
	return new Zombie(chosen_name, this->type);
}

void	ZombieHorde::announce()
{
	for (unsigned i = 0; i < this->N; i++)
		this->horde[i]->announce();
}