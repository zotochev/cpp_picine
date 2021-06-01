#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie(const std::string& name_ = "John Doe", const std::string& type_ = "walker");
	~Zombie();

	void	announce();

private:
	std::string	type;
	std::string	name;
};

#endif
