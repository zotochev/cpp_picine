#ifndef TACTICAL_MARINE_HPP
#define TACTICAL_MARINE_HPP

#include <iostream>

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const & other);
		~TacticalMarine();

		TacticalMarine & operator=(TacticalMarine const & other);

		ISpaceMarine*	clone() const;
		void			battleCry() const;
		void			rangedAttack() const;
		void			meleeAttack() const;

};

#endif
