#include "Zombie.hpp"

Zombie::Zombie(const std::string& name_, const std::string& type_)
{
	this->name = name_;
	this->type = type_;
	this->announce();
}

Zombie::~Zombie()
{}

void Zombie::announce()
{
	std::cout << "<" << this->name << " ";
	std::cout << "(" << this->type << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}

