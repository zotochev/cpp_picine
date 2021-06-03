#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	private:
		unsigned int	_xp;
		std::string		_type;

	public:
		AMateria();
		AMateria(AMateria const & other);
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria & operator=(AMateria const & right);

		std::string const &	getType() const;
		unsigned int		getXP() const;

		void				setType(std::string const & type);
		void				setXP(unsigned int xp);

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

std::ostream & operator<<(std::ostream & os, AMateria const * obj);

#endif
