#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		Character();
		AMateria**	_materia_slots;
		std::string	_name;

		void				clean_materia_slots();
		AMateria**			clone_materia_slots() const;
	
	public:
		Character(std::string const & name);
		Character(Character const & other);
		~Character();

		Character & operator=(Character const & right);

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter & target);
		int					materia_available_count() const;

		std::string			getStatus() const;
};

std::ostream &	operator<<(std::ostream & os, ICharacter const & obj);

#endif
