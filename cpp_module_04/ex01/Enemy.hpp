#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

class Enemy
{
	private:
		Enemy();
		int			hp_;
		std::string	type_;

	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & other);
		virtual ~Enemy();
		Enemy &	operator=(Enemy const & other);

		std::string const getType() const;
		int	getHP() const;

		void	setType(std::string const & type);
		void	setHP(int hp);

		virtual void takeDamage(int);

		std::string getPrettyName() const;

};

std::ostream & operator<<(std::ostream & os, Enemy const & obj);

#endif
