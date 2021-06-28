#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*a = new Bureaucrat("Conrad Brean", 1);
	Bureaucrat	*b = new Bureaucrat("Stanley Motss", 15);
	Bureaucrat	*c = new Bureaucrat("Winifred Ames", 150);

	std::cout << *a;
	std::cout << *b;
	std::cout << *c;

	try
	{
		a->incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		c->decGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b->decGrade();
		b->decGrade();
		std::cout << *b;
		b->incGrade();
		b->incGrade();
		b->incGrade();
		b->incGrade();
		std::cout << *b;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete a;
	delete b;
	delete c;

	return 0;
}
