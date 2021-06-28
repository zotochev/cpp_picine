#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("SHRUBBERY CREATION FORM", 145, 137, "no target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: Form("SHRUBBERY CREATION FORM", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
	: Form(other.getName(), other.getGradeSign(), other.getGradeExecute(), other.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & right)
{
	if (this != &right)
	{
		*((Form *)this) = (Form const &)right;
	}
	return *this;
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream file;

	file.open("execution_shrubbery.txt");
	for (int i = 0; i < 3; ++i)
		file << tree;
	file.close();
}

//	https://ascii.co.uk/art/tree
std::string	ShrubberyCreationForm::tree =
					"              v .   ._, |_  .,			\n"
					"           `-._\\/  .  \\ /    |/_		\n"
					"               \\\\  _\\, y | \\//			\n"
					"         _\\_.___\\\\, \\\\/ -.\\||			\n"
					"           `7-,--.`._||  / / ,			\n"
					"           /'     `-. `./ / |/_.'		\n"
					"                     |    |//			\n"
					"                     |_    /			\n"
					"                     |-   |			\n"
					"                     |   =|			\n"
					"                     |    |			\n"
					"--------------------/ ,  . \\--------._	\n"
					"                                       	\n";

