#include "AWeapon.hpp"

AWeapon::~AWeapon()
{}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
	: name_(name)
	, damage_(damage)
	, apcost_(apcost)
{}

AWeapon & AWeapon::operator=(AWeapon const & other)
{
	if (this != &other)
	{
		name_ = other.getName();
		damage_ = other.getDamage();
		apcost_ = other.getAPCost();
		attack_sound_ = other.getAttackSound();
	}
	return *this;
}


std::string const	AWeapon::getName() const { return name_; }
int					AWeapon::getAPCost() const { return apcost_; }
int					AWeapon::getDamage() const { return damage_; }
std::string			AWeapon::getAttackSound() const { return attack_sound_; }

void				AWeapon::setName(std::string const & name) { name_ = name; }
void				AWeapon::setAttackSound(std::string const & attack_sound) { attack_sound_ = attack_sound; }
void				AWeapon::setAPCost(int apcost) { apcost_ = apcost; }
void				AWeapon::setDamage(int damage) { damage_ = damage; }

void	AWeapon::attack() const
{
	std::cout << getAttackSound() << std::endl;
}
