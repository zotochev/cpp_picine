#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP

#include <iostream>

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & other);
		~SuperMutant();

		SuperMutant & operator=(SuperMutant const & other);

		virtual void	takeDamage(int damage);

	private:
};

#endif
