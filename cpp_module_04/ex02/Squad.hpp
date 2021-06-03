#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	public:
		Squad();
		Squad(Squad const & other);
		~Squad();

		Squad & operator=(Squad const & rhs);

		virtual int		getCount() const;
		virtual			ISpaceMarine* getUnit(int) const;
		virtual int		push(ISpaceMarine*);
		
		void			vanish_squad();
		ISpaceMarine**	clone_squad() const;
		bool			is_in_squad(ISpaceMarine*);
	
	private:
		ISpaceMarine**	_unit;
		int				_unit_count;
};

#endif
