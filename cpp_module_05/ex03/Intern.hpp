#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const & other);
		~Intern();

		Intern &	operator=(Intern const & right);

		Form		*makeForm(std::string const & form_name, std::string const & target);

};

#endif
