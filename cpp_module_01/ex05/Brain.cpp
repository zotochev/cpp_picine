#include <sstream>
#include "Brain.hpp"

Brain::Brain()
{}

Brain::~Brain()
{}

std::string	Brain::identify() const
{
	std::stringstream	temp;

	temp << this;
	return temp.str();
}

void	Brain::set_weight(unsigned weight_)
{
	this->weight = weight_;
}
