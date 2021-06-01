#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	~Brain();

	std::string	identify() const;
	void		set_weight(unsigned weight_);

private:
	unsigned	weight;
};

#endif
