#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	try_sign(Bureaucrat b, Form f)
{
	try
	{
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << f << std::endl;
}

int	main()
{
	Bureaucrat	*b1 = new Bureaucrat("Fad King", 10); 
	Bureaucrat	*b2 = new Bureaucrat("Sklansky", 25); 

	Form		*f1 = new Form("Why does the dog wag its tail?", 40, 70);
	Form		*f2 = new Form("Because a dog is smarter than its tail.", 20, 30);


	try_sign(*b1, *f1);
	try_sign(*b1, *f2);
	try_sign(*b2, *f1);
	try_sign(*b2, *f2);

	delete b1;
	delete b2;
	delete f1;
	delete f2;
	return 0;
}
