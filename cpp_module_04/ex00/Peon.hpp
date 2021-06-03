#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(const std::string & name);
	Peon(const Peon & other);
	~Peon();

	void	getPolymorphed() const;
	Peon & operator=(const Peon & other);
private:
	Peon();
};

#endif
