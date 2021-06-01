#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "common.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(std::string const & name);
	NinjaTrap(NinjaTrap const & other);
	~NinjaTrap();

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	std::string			get_health() const;

	void				ninjaShoebox(NinjaTrap const & other) const;
	void				ninjaShoebox(FragTrap const & other) const;
	void				ninjaShoebox(ScavTrap const & other) const;

	NinjaTrap & operator=(NinjaTrap const & other);

private:
	static const char	*creation_list[];
	static unsigned 	creation_list_len;
	static const char	*take_damage_list[];
	static unsigned		take_damage_list_len;
	static const char	*be_repaired_list[];
	static unsigned		be_repaired_list_len;

};

#endif
