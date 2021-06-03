#ifndef ISQUAD_HPP
#define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
//	private:
//		ISquad();
//		ISquad(ISquad const & other);
//		ISquad & operator=(ISquad const & other);

	public:
		virtual ~ISquad() {}
		virtual int				getCount() const = 0;
		virtual ISpaceMarine*	getUnit(int) const = 0;
		virtual int				push(ISpaceMarine*) = 0;
};

#endif
