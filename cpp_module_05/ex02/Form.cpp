#include "Form.hpp"

Form::Form()
	: _name("no name")
	, _signed(false)
	, _grade_sign(0)
	, _grade_execute(0)
	, _target("no target")
{}

Form::Form(std::string const & name, int grade_sign, int grade_execute, std::string const & target)
	: _name(name)
	, _signed(false)
	, _grade_sign(grade_sign)
	, _grade_execute(grade_execute)
	, _target(target)
{
	if (_grade_sign < Bureaucrat::gratest_grade
			|| _grade_execute < Bureaucrat::gratest_grade)
		throw(GradeTooHighException());
	if (_grade_sign > Bureaucrat::lowest_grade
			|| _grade_execute > Bureaucrat::lowest_grade)
		throw(GradeTooHighException());
}

Form::Form(Form const & other)
	: _name(other.getName())
	, _signed(other.getSigned())
	, _grade_sign(other.getGradeSign())
	, _grade_execute(other.getGradeExecute())
	, _target(other.getTarget())
{}

Form::~Form()
{}

Form &	Form::operator=(Form const & right)
{
	if (this != &right)
	{
		static_cast<std::string>(_name) = right.getName();
		_signed = right.getSigned();
		_target = right.getTarget();
	}
	return *this;
}

bool	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_sign + 50)
		throw GradeTooLowException();
	if (bureaucrat.getGrade() <= _grade_sign)
		_signed = true;
	return _signed;
}

bool	Form::execute(Bureaucrat const & bureaucrat) const
{
	if (getSigned() && bureaucrat.getGrade() <= _grade_execute)
	{
		return true;
	}
	else
	{
		throw GradeTooLowException();
		return false;
	}
}

std::ostream &	operator<<(std::ostream & os, Form const & right)
{
	os	<< "[FORM " << right.getName()
		<< " grade (sign|execute)=|"
		<< right.getGradeSign() << "|"
		<< right.getGradeExecute() << "| " 
		<< "TARGET: " << right.getTarget()
		<< " sign place ( ";
	if (right.getSigned())
		os	<< "X";
	else
		os	<< " ";
	os	<< " )]";
	return os;
}

std::string	Form::getName() const					{ return _name; }
bool		Form::getSigned() const					{ return _signed; }
int			Form::getGradeSign() const				{ return _grade_sign; }
int			Form::getGradeExecute() const			{ return _grade_execute; }
std::string	Form::getTarget() const					{ return _target; }

void		Form::setName(std::string const & name)		{ static_cast<std::string>(_name) = name; }
void		Form::setSigned(bool sign)					{ _signed = sign; }
void		Form::setTarget(std::string const & target)	{ _target = target; }

