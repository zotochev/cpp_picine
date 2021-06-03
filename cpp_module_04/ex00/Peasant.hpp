#ifndef PEASANT_HPP
#define PEASANT_HPP

#include <iostream>
#include "Victim.hpp"

class Peasant : public Victim
{
public:
	Peasant(const std::string & name);
	Peasant(const Peasant & other);
	~Peasant();

	void	getPolymorphed() const;
	Peasant & operator=(const Peasant & other);
private:
	Peasant();
};

#endif
