#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "common.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap();
	SuperTrap(SuperTrap const & other);
	SuperTrap(std::string const & name);
	~SuperTrap();
	SuperTrap & operator=(SuperTrap const & other);

	using				FragTrap::beRepaired;
	using				FragTrap::rangedAttack;
	using				NinjaTrap::meleeAttack;

private:
	static const char	*creation_list[];
	static unsigned 	creation_list_len;

//	using				FragTrap::hit_points_;
//	using				FragTrap::max_hit_points_;
//	using				NinjaTrap::energy_points_;
//	using				NinjaTrap::max_energy_points_;
//	using				level_;
//	using				name_;
//	using				NinjaTrap::melee_attack_damage_;
//	using				FragTrap::ranged_attack_damage_;
//	using				FragTrap::armor_damage_reduction_;
};

#endif
