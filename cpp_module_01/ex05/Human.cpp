#include "Human.hpp"
#include "Brain.hpp"

Human::Human() : brain(Brain())
{}

Human::~Human()
{}

std::string	Human::identify() const
{
	return this->brain.identify();
}

Brain	&Human::getBrain()
{
	return (Brain &)(this->brain);
}
