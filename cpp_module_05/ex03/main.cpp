#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
    Form		*f1;
    Form		*f2;
    Form		*f3;
    Form		*f4;
    Intern		i1;
    Bureaucrat	b1 = Bureaucrat("Indian Jute", 3);

    f1 = i1.makeForm("robotomy request", "The Mauler Twins");
    f2 = i1.makeForm("presidential pardon", "Machine Head");
    f3 = i1.makeForm("shrubbery creation", "Thragg");
    f4 = i1.makeForm("therer is no such form", "Allen the Alien");

    std::cout << *f1 << std::endl;
    std::cout << *f2 << std::endl;
    std::cout << *f3 << std::endl;

	std::cout << "~~~~~~~~~~~~" << std::endl;
    b1.signForm(*f1);
    b1.executeForm(*f1);
	std::cout << "~~~~~~~~~~~~" << std::endl;

	if (nullptr != f1)
		delete f1;
	if (nullptr != f2)
		delete f2;
	if (nullptr != f3)
		delete f3;
	if (nullptr != f4)
		delete f4;
    return 0;
}
