#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const & other)
	: _name(other.getName())
	, _grade(other.getGrade())
{}

Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name)
	, _grade(grade)
{
	if (grade < gratest_grade)
		throw GradeTooHighException();
	else if (grade > lowest_grade)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & right)
{
	if (this != &right)
	{
		static_cast<std::string>(_name) = right.getName();
		_grade = right.getGrade();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & right)
{
	os	<< right.getName() << ", bureaucrat grade "
		<< right.getGrade()
		<< std::endl;

	return os;
}

void	Bureaucrat::incGrade()
{
	if (_grade == gratest_grade)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade == lowest_grade)
		throw GradeTooLowException();
	else
		_grade++;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cout << "from exception. name: " << Bureaucrat::_name << std::endl;
	std::cout << "from exception. grade: " << Bureaucrat::_grade << std::endl;
	return "Grade is too low (Exception)";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (Exception)";
}

std::string		Bureaucrat::getName() const { return _name; }
int				Bureaucrat::getGrade() const { return _grade; }

int	Bureaucrat::gratest_grade = 1;
int	Bureaucrat::lowest_grade = 150;
