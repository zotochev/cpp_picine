#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(const std::string &type_);
	~Weapon();

	std::string	getType() const;
	void		setType(const std::string &type_);

private:
	std::string	type;
};

#endif