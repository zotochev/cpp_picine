#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(100, 100, 120, 120, 1, "no name", 60, 20, 5)
{
	std::cout << "(default SuperTrap constructor) " << FragTrap::name() << std::endl;
}

SuperTrap::SuperTrap(std::string const & name) : ClapTrap(100, 100, 120, 120, 1, name, 60, 20, 5)
{
	std::cout << "(name SuperTrap constructor) " << FragTrap::name() << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & other) : ClapTrap(
												other.hit_points(),
												other.max_hit_points(),
												other.energy_points(),
												other.max_energy_points(),
												other.level(),
												other.name(),
												other.melee_attack_damage(),
												other.ranged_attack_damage(),
												other.armor_damage_reduction()
												)
{
	std::cout << "(copy SuperTrap constructor) " << FragTrap::name() << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "(SuperTrap destructor) " << FragTrap::name() << std::endl;
}

SuperTrap & SuperTrap::operator = (SuperTrap const & other)
{
	if (this != &other)
	{
		FragTrap::set_hit_points(other.hit_points());
		FragTrap::set_max_hit_points(other.max_hit_points());
		FragTrap::set_energy_points(other.energy_points());
		FragTrap::set_max_energy_points(other.max_energy_points());
		FragTrap::set_level(other.level());
		FragTrap::set_name(other.name());
		FragTrap::set_melee_attack_damage(other.melee_attack_damage());
		FragTrap::set_ranged_attack_damage(other.ranged_attack_damage());
		FragTrap::set_armor_damage_reduction(other.armor_damage_reduction());
	}
	std::cout << "(operator \"=\" used)" << FragTrap::name() << std::endl;
	return *this;
}

unsigned int	SuperTrap::creation_list_len = 6;

const char*	SuperTrap::creation_list[] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

