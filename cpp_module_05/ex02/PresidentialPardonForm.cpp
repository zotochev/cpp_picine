#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PRESIDENTIAL REQIEST FROM", 25, 5, "no target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form("PRESIDENTIAL REQIEST FROM", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
	: Form(other.getName(), other.getGradeSign(), other.getGradeExecute(), other.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & right)
{
	if (this != &right)
	{
		*((Form *)this) = (Form const &)right;
	}
	return *this;
}

void	PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
