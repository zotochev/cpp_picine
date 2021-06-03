#ifndef GROUND_HPP
#define GROUND_HPP

#include "AMateria.hpp"

class Ground : public AMateria
{
	public:
		Ground();
		Ground(Ground const & other);
		~Ground();

		Ground & operator=(Ground const & right);

		AMateria*	clone() const;
		void	use(ICharacter & target);
};

#endif
