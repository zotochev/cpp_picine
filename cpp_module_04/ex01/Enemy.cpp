#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
	: hp_(hp)
	, type_(type)
{
	//std::cout << "Enemy type of " << type_ << " created" << std::endl;
}

Enemy::Enemy(Enemy const & other)
	: hp_(other.getHP())
	, type_(other.getType())
{
	//std::cout << "Enemy type of " << type_ << " created" << std::endl;
}

Enemy::~Enemy()
{
	//std::cout << "Enemy type of " << type_ << " destructed" << std::endl;
}

Enemy &	Enemy::operator=(Enemy const & other)
{
	if (this != &other)
	{
		setHP(other.getHP());
		setType(other.getType());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, Enemy const & obj)
{
	os << obj.getPrettyName();
	return os;
}

std::string const	Enemy::getType() const { return type_; }
int					Enemy::getHP() const { return hp_; }

void	Enemy::setType(std::string const & type) { type_ = type; }
void	Enemy::setHP(int hp) { hp_ = hp; }

void	Enemy::takeDamage(int damage)
{
	if (getHP() > 0 && damage >= 0)
	{
		if (damage > getHP())
		{
			setHP(0);
		}
		else
			setHP(getHP() - damage);
	}
}

std::string	Enemy::getPrettyName() const
{
	std::stringstream ss;

	ss << "<" << getType() << " hp:" << std::setw(3) << getHP() << ">";
	return ss.str();	
}
