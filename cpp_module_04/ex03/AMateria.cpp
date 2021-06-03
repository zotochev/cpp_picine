#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(AMateria const & other)
	: _xp(other.getXP())
	, _type(other.getType())
{}

AMateria::AMateria(std::string const & type)
	: _xp(0)
	, _type(type)
{}

AMateria::~AMateria()
{}

AMateria & AMateria::operator=(AMateria const & right)
{
	if (this != &right)
	{
		_type = right.getType();
		_xp = right.getXP();
	}
	return *this;
}

void	AMateria::use(ICharacter & target)
{
	(void)target;

	_xp += 10;
}

std::string const &	AMateria::getType() const	{ return _type; }
unsigned int		AMateria::getXP() const		{ return _xp; }

void	AMateria::setType(std::string const & type) { _type = type; }
void	AMateria::setXP(unsigned int xp) { _xp = xp; }
