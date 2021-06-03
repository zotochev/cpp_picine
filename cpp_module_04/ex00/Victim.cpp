#include "Victim.hpp"

Victim::Victim()
{}

Victim::Victim(const Victim & other) : name_(other.name())
{
	std::cout << "Some random victim called " << name() << " just appeared!" << std::endl;
}

Victim::Victim(const std::string & name) : name_(name)
{
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name_ << " just died for no apparent reason!" << std::endl;
}

Victim & Victim::operator=(const Victim & other)
{
	if (this != &other)
	{
		name_ = other.name();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, const Victim & obj)
{
	os << "I'm " << obj.name() << " and I like otters!" << std::endl;
	return os;
}

std::string	Victim::name() const
{
	return name_;
}

void	Victim::set_name(const std::string & name)
{
	name_ = name;
}

void	Victim::getPolymorphed() const
{
	std::cout << name_ << " has been turned into a cute little sheep!" << std::endl;
}
