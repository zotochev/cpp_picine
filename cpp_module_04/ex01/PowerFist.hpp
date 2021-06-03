#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const & other);
		virtual ~PowerFist();
		PowerFist & operator=(PowerFist const & other);
		
		void	attack() const;
};

#endif
