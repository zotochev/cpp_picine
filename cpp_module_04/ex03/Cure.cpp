#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(Cure const & other)
{
	*this = other;
}

Cure::~Cure()
{}

Cure & Cure::operator=(Cure const & right)
{
	if (this != &right)
	{
		setType(right.getType());
		setXP(right.getXP());
	}
	return *this;
}

AMateria*	Cure::clone() const
{
	return (AMateria*) new Cure(*this);
}

void		Cure::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout	<< "* heals "
				<< target.getName() << "'s wounds *"
				<< std::endl;
}
