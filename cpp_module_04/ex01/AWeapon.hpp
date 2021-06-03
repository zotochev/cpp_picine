#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	private:
		AWeapon();
		std::string		name_;
		int				damage_;
		int				apcost_;
		std::string		attack_sound_;

	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & other);
		virtual ~AWeapon();

		AWeapon & operator=(AWeapon const & other);

		std::string	const	getName() const;
		int					getAPCost() const;
		int					getDamage() const;
		std::string			getAttackSound() const;

		void		setName(std::string const & name);
		void		setAPCost(int apcost);
		void		setDamage(int damage);
		void		setAttackSound(std::string const & attack_sound);

		virtual void 		attack() const = 0;
};

std::ostream	operator<<(std::ostream & os, AWeapon const & obj);

#endif
