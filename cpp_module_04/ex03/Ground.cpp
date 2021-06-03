#include "Ground.hpp"

Ground::Ground() : AMateria("ground")
{}

Ground::Ground(Ground const & other)
{
	*this = other;
}

Ground::~Ground()
{}

Ground & Ground::operator=(Ground const & right)
{
	if (this != &right)
	{
		setType(right.getType());
		setXP(right.getXP());
	}
	return *this;
}

AMateria*	Ground::clone() const
{
	return (AMateria*) new Ground(*this);
}

void		Ground::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout	<< "* "
				<< target.getName()
				<< " now can see the location of all loose resources"
			   	<< " *"
				<< std::endl;
}
