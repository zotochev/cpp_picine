#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <sstream>

# define RED		"\x1B[31m"
# define GRN   		"\x1B[32m"
# define YEL   		"\x1B[33m"
# define BLU   		"\x1B[34m"
# define MAG   		"\x1B[35m"
# define CYN   		"\x1B[36m"
# define RESET 		"\x1B[0m"

class FragTrap
{
public:
	FragTrap();
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & other);
	~FragTrap();
	FragTrap &	operator=(FragTrap const & other);

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

	typedef void		(FragTrap::*t_attack)(const std::string &);

private:
	unsigned int		hit_points_;
	unsigned int		max_hit_points_;
	unsigned int		energy_points_;
	unsigned int		level_;
	std::string			name_;
	unsigned int		melee_attack_damage_;
	unsigned int		ranged_attack_damage_;
	unsigned int		armor_damage_reduction_;

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
