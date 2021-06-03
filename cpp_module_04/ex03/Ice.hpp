#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const & other);
		~Ice();

		Ice & operator=(Ice const & right);

		AMateria*	clone() const;
		void	use(ICharacter & target);
};

#endif
