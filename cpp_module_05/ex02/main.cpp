#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static void	test_1(Bureaucrat b, ShrubberyCreationForm f1)

{
    try
    {
        b.signForm(f1);
        b.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

static void	test_2(Bureaucrat b, RobotomyRequestForm f1)

{
    try
    {
        b.signForm(f1);
        b.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

static void	test_3(Bureaucrat b, PresidentialPardonForm f1)

{
    try
    {
        b.signForm(f1);
        b.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

int	main(void)
{
    Bureaucrat						b1("B1", 1);
    Bureaucrat						b2("B2", 140);
    Bureaucrat						b3("B3", 147);

	Bureaucrat						b4("B2", 50);

    Bureaucrat						b5("B2", 20);

	// 145 137
    ShrubberyCreationForm			f1("SCF_1");
    ShrubberyCreationForm			f2("SCF_2");

	// 72 45
	RobotomyRequestForm				f3("RRF_1");

	// 25 5
	PresidentialPardonForm			f6("PPF_1");

    test_1(b3, f1);
    std::cout << std::endl;

    test_1(b2, f1);
    std::cout << std::endl;

    test_1(b1, f1);
    std::cout << std::endl;

	b1.signForm(f1);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;


	std::cout << f3 << std::endl;
    test_2(b3, f3);
    std::cout << std::endl;
    test_2(b4, f3);
    std::cout << std::endl;
    test_2(b1, f3);
    std::cout << std::endl;

	std::cout << f6 << std::endl;
    test_3(b3, f6);
    std::cout << std::endl;
    test_3(b5, f6);
    std::cout << std::endl;
    test_3(b1, f6);
    std::cout << std::endl;

    return 0;
}
