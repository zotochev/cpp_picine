#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "common.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(std::string const & name);
	NinjaTrap(NinjaTrap const & other);
	~NinjaTrap();

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);

	void				ninjaShoebox(NinjaTrap const & other) const;
	void				ninjaShoebox(FragTrap const & other) const;
	void				ninjaShoebox(ScavTrap const & other) const;

	NinjaTrap & operator=(NinjaTrap const & other);

private:
	static const char	*creation_list[];
	static unsigned 	creation_list_len;
};

#endif
