#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <sstream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		Character();

		std::string name_;
		int			ap_;
		AWeapon		*weapon_;

	public:
		Character(std::string const & name);
		Character(Character const & other);
		~Character();

		Character & operator=(Character const & other);

		void				recoverAP();
		void				equip(AWeapon *);
		void				attack(Enemy *);

		std::string const	getName() const;
		int					getAP() const;
		AWeapon				*getWeapon() const;

		void				setName(std::string const & name);
		void				setAP(int ap);
};

std::ostream &	operator<<(std::ostream & os, Character const & obj);

#endif
