#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(Ice const & other)
{
	*this = other;
}

Ice::~Ice()
{}

Ice & Ice::operator=(Ice const & right)
{
	if (this != &right)
	{
		setType(right.getType());
		setXP(right.getXP());
	}
	return *this;
}

AMateria*	Ice::clone() const
{
	return (AMateria*) new Ice(*this);
}

void		Ice::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName() << " *"
				<< std::endl;
}
