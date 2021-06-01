#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "common.hpp"

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(ClapTrap const & other);
	ClapTrap(
			unsigned int hit_points,
			unsigned int max_hit_points,
			unsigned int energy_points,
			unsigned int max_energy_points,
			unsigned int level,
			std::string const & name,
			unsigned int melee_attack_damage,
			unsigned int ranged_attack_damage,
			unsigned int armor_damage_reduction
			);
	~ClapTrap();
	ClapTrap &	operator=(ClapTrap const & other);

	virtual void	takeDamage(unsigned int amount) = 0;
	virtual void	beRepaired(unsigned int amount) = 0;

	std::string		get_health() const;

	unsigned int	hit_points() const;
	unsigned int	max_hit_points() const;
	unsigned int	energy_points() const;
	unsigned int	max_energy_points() const;
	unsigned int	level() const;
	std::string		name() const;
	unsigned int	melee_attack_damage() const;
	unsigned int	ranged_attack_damage() const;
	unsigned int	armor_damage_reduction() const;

	void			set_hit_points(unsigned int num);
	void			set_max_hit_points(unsigned int num);
	void			set_energy_points(unsigned int num);
	void			set_max_energy_points(unsigned int num);
	void			set_level(unsigned int num);
	void			set_name(std::string name);
	void			set_melee_attack_damage(unsigned int num);
	void			set_ranged_attack_damage(unsigned int num);
	void			set_armor_damage_reduction(unsigned int num);

private:
	unsigned int	hit_points_;
	unsigned int	max_hit_points_;
	unsigned int	energy_points_;
	unsigned int	max_energy_points_;
	unsigned int	level_;
	std::string		name_;
	unsigned int	melee_attack_damage_;
	unsigned int	ranged_attack_damage_;
	unsigned int	armor_damage_reduction_;

};


#endif
