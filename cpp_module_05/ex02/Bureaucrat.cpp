#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	Bureaucrat::signForm(Form & form)
{
	if (form.beSigned(*this))
	{
		std::cout	<< _name << " " << getGrade() << " signs "
					<< form.getName() << std::endl;
	}
	else
	{
		std::cout	<< _name << " cannot sign "
					<< form.getName() << " because his grade is "
					<< getGrade() << " but to sign this form it requiered to have grade "
					<< form.getGradeSign() <<  std::endl;
	}
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

void	Bureaucrat::executeForm(Form const & form)
{
	if (form.execute(*this))
	{
		std::cout << _name << " executes " << form.getName() << std::endl;
		form.action();
	}
	else
	{
		std::cout << _name << " can not execute " << form.getName() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
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
