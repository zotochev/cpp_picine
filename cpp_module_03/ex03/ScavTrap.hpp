#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "common.hpp"
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const & name);
	ScavTrap(ScavTrap const & other);
	~ScavTrap();
	ScavTrap &	operator=(ScavTrap const & other);

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);

	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	void				challengeNewcomer(std::string const & target);

	std::string			get_health() const;

	void				challenge_1(std::string const & target);
	void				challenge_2(std::string const & target);
	void				challenge_3(std::string const & target);
	void				challenge_4(std::string const & target);
	void				challenge_5(std::string const & target);
	void				challenge_6(std::string const & target);

	typedef void		(ScavTrap::*t_challenge)(std::string const & target);

private:
	void				challenges_init();
	t_challenge			challenges[6];

	static const char		*creation_list[];
	static unsigned int		creation_list_len;
	static const char		*take_damage_list[];
	static unsigned int		take_damage_list_len;
	static const char		*be_repaired_list[];
	static unsigned int		be_repaired_list_len;
	static const char		*challengeNewcomer_list[];
	static unsigned int		challengeNewcomer_list_len;
};


#endif
