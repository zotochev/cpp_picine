#include "Pony.hpp"

Pony::Pony(const std::string& name_,
		   const std::string& fur_color_,
		   const std::string& battle_scream_)
{
	this->name = name_;
	this->fur_color = fur_color_;
	this->battle_scream = battle_scream_;
	std::cout	<< "New " << this->fur_color
				<< " pony named " << this->name
				<< " created" << std::endl;
}

Pony::~Pony()
{
	std::cout << this->name << ": Bye!" << std::endl;
	std::cout << "Pony named " << this->name << " destructed" << std::endl;
}

void	Pony::say()
{
	std::cout << this->name << ": ";
	std::cout << this->battle_scream << std::endl;
}