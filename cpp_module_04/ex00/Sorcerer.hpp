#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(const std::string & name, const std::string & title);
	Sorcerer(const Sorcerer & other);
	~Sorcerer();
	Sorcerer &	operator=(const Sorcerer & other);

	void	polymorph(Victim const &) const;

	std::string	name() const;
	std::string	title() const;
	void	set_name(const std::string & name);
	void	set_title(const std::string & title);

private:
	Sorcerer();

	std::string	name_;
	std::string	title_;
};

std::ostream & operator<<(std::ostream & os, const Sorcerer & obj);

#endif
