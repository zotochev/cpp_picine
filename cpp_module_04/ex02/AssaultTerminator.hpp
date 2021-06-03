#ifndef ASSAULT_TERMINATOR_HPP
#define ASSAULT_TERMINATOR_HPP

#include <iostream>

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const & other);
		~AssaultTerminator();

		AssaultTerminator & operator=(AssaultTerminator const & other);

		ISpaceMarine*	clone() const;
		void			battleCry() const;
		void			rangedAttack() const;
		void			meleeAttack() const;

};

#endif
