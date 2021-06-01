#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "common.hpp"
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & other);
	~FragTrap();
	FragTrap &	operator=(FragTrap const & other);

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);

	void				vaulthunter_dot_exe(std::string const & target);

	void				attack_1(std::string const & target);
	void				attack_2(std::string const & target);
	void				attack_3(std::string const & target);
	void				attack_4(std::string const & target);
	void				attack_5(std::string const & target);
	void				attack_6(std::string const & target);

	typedef void		(FragTrap::*t_attack)(std::string const &);

private:
	void				attacks_init();
	t_attack			attacks[6];

	static const char	*creation_list[];
	static unsigned 	creation_list_len;
	static const char	*vaulthunter_dot_exe_list[];
};


#endif
