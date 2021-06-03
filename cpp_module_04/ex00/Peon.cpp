#include "Peon.hpp"

Peon::Peon()
{}

Peon::Peon(const Peon & other) : Victim(other.name())
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const std::string & name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark.." << std::endl;
}

void	Peon::getPolymorphed() const
{
	std::cout << name() << " has been turned into a pink pony!" << std::endl;
}

Peon &	Peon::operator=(const Peon & other)
{
	if (this != &other)
	{
		set_name(other.name());
	}
	return *this;
}
