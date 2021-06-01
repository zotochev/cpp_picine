#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "common.hpp"
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & other);
	~FragTrap();

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	void				vaulthunter_dot_exe(std::string const & target);

	std::string			get_health() const;

	void				attack_1(std::string const & target);
	void				attack_2(std::string const & target);
	void				attack_3(std::string const & target);
	void				attack_4(std::string const & target);
	void				attack_5(std::string const & target);
	void				attack_6(std::string const & target);

	typedef void		(FragTrap::*t_attack)(std::string const &);

	FragTrap &	operator=(FragTrap const & other);

private:
	void				attacks_init();
	t_attack			attacks[6];

	static const char	*creation_list[];
	static unsigned 	creation_list_len;
	static const char	*take_damage_list[];
	static unsigned		take_damage_list_len;
	static const char	*be_repaired_list[];
	static unsigned		be_repaired_list_len;
	static const char	*vaulthunter_dot_exe_list[];
};


#endif
