#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("ROBOTOMY REQUEST FORM", 72, 45, "no target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form("ROBOTOMY REQUEST FORM", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
	: Form(other.getName(), other.getGradeSign(), other.getGradeExecute(), other.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & right)
{
	if (this != &right)
	{
		*((Form *)this) = (Form const &)right;
	}
	return *this;
}

void	RobotomyRequestForm::action() const
{
	std::srand(std::time(nullptr));
	std::cout << "Brrzzzzzz Br Br Brrrrzzzzzzz ..." << std::endl;
	if (0 == std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << " Robotomization failure. "<< getTarget() << " was not robotomized" << std::endl;
}
