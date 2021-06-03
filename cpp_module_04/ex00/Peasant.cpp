#include "Peasant.hpp"

Peasant::Peasant()
{}

Peasant::Peasant(const Peasant & other) : Victim(other.name())
{
	std::cout << "Ready to work" << std::endl;
}

Peasant::Peasant(const std::string & name) : Victim(name)
{
	std::cout << "Ready to work" << std::endl;
}

Peasant::~Peasant()
{
	std::cout << "That's it. I'm dead" << std::endl;
}

void	Peasant::getPolymorphed() const
{
	std::cout << name() << " has been turned into an otter!" << std::endl;
}

Peasant &	Peasant::operator=(const Peasant & other)
{
	if (this != &other)
	{
		set_name(other.name());
	}
	return *this;
}
