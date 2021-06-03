#include "Character.hpp"

Character::Character(std::string const & name)
	: name_(name)
	, ap_(40)
	, weapon_(nullptr)
{}

Character::Character(Character const & other)
	: name_(other.getName())
	, ap_(other.getAP())
	, weapon_(other.getWeapon())
{}

Character::~Character()
{}

Character &	Character::operator=(Character const & other)
{
	if (this != &other)
	{
		setName(other.getName());
		setAP(other.getAP());
		equip(other.getWeapon());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, Character const & obj)
{
	AWeapon	*w = obj.getWeapon();

	if (w != nullptr)
		os << obj.getName() << " has " << obj.getAP() << " AP and wields a " << w->getName() << std::endl;
	else
		os << obj.getName() << " has " << obj.getAP() << " AP and is unarmed" << std::endl;
	return os;
}

void	Character::recoverAP()
{
	if (getAP() + 10 >= 40)
		setAP(40);
	else
		setAP(getAP() + 10);
}

void	Character::attack(Enemy * enemy_obj)
{
	AWeapon	*w = getWeapon();

	if (enemy_obj != nullptr && getWeapon() != nullptr && getAP() >= w->getAPCost())
	{
		setAP(getAP() - w->getAPCost());
		std::cout << getName() << " attacks " << enemy_obj->getType() << " with a " << w->getName() << std::endl;
		w->attack();
		enemy_obj->takeDamage(w->getDamage());
	}
}

void	Character::equip(AWeapon * weapon)
{
	weapon_ = weapon;
}

std::string const	Character::getName() const		{ return name_; }
int					Character::getAP() const		{ return ap_; }
AWeapon*			Character::getWeapon() const	{ return weapon_; }

void				Character::setName(std::string const & name)	{ name_ = name; }
void				Character::setAP(int ap)						{ ap_ = ap; }


