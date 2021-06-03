#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{}

Sorcerer::Sorcerer(const std::string & name, const std::string & title)
	: name_(name), title_(title)
{
	std::cout << name_ << ", " << title_ << ", is born!" << std::endl; 
}

Sorcerer::~Sorcerer()
{
	std::cout << name_ << ", " << title_ << "is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::name() const
{
	return name_;
}

std::string Sorcerer::title() const
{
	return title_;
}

void	Sorcerer::set_name(const std::string & name)
{
	name_ = name;
}

void	Sorcerer::set_title(const std::string & title)
{
	title_ = title;
}

void	Sorcerer::polymorph(Victim const & obj) const
{
	obj.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(const Sorcerer & other)
{
	if (this != &other)
	{
		name_ = other.name();
		title_ = other.title();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Sorcerer & obj)
{
	os << "I am " << obj.name() << ", " << obj.title() << ", and I like ponies!" << std::endl;
	return os;
}
