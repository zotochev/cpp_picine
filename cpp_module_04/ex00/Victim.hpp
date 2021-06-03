#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "iostream"

class Victim
{
public:
	Victim();
	Victim(const std::string & name);
	Victim(const Victim & other);
	virtual ~Victim();

	Victim & 	operator=(const Victim & other);

	virtual void		getPolymorphed() const;
	std::string	name() const;
	void		set_name(const std::string & name);

private:

	std::string	name_;

};

std::ostream & 	operator<<(std::ostream & os, const Victim & obj);

#endif
