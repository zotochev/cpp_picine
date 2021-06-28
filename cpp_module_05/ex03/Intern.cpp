#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & other)
{
	*this = other;
}

Intern::~Intern()
{}

Intern &	Intern::operator=(Intern const & right)
{
	(void)right;
	return *this;
}

Form	*makeShrubberyCreationForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

Form	*makeRobotomyRequestForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

Form	*makePresidentialPardonForm(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

enum	form{srub, robo, pardon};

Form	*Intern::makeForm(std::string const & form_name, std::string const & target)
{
	typedef	Form *(*func)(std::string const &);

	std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	func	form_functions[] = {
		makeShrubberyCreationForm,
		makeRobotomyRequestForm,
		makePresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (form_names[i] == form_name)
			return form_functions[i](target);
	}

	std::cout << "There is no matching form for your request" << std::endl;
	return nullptr;
}
