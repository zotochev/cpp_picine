#include "Form.hpp"

Form::Form()
	: _name("no name")
	, _signed(false)
	, _grade_sign(0)
	, _grade_execute(0)
{}

Form::Form(std::string const & name, int grade_sign, int grade_execute)
	: _name(name)
	, _signed(false)
	, _grade_sign(grade_sign)
	, _grade_execute(grade_execute)
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
{}

Form::~Form()
{}

Form &	Form::operator=(Form const & right)
{
	if (this != &right)
	{
		static_cast<std::string>(_name) = right.getName();
		_signed = right.getSigned();
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

std::string	Form::getName() const			{ return _name; }
bool		Form::getSigned() const			{ return _signed; }
int			Form::getGradeSign() const		{ return _grade_sign; }
int			Form::getGradeExecute() const	{ return _grade_execute; }

std::ostream &	operator<<(std::ostream & os, Form const & right)
{
	os	<< "[FORM "
		<< " grade (sign|execute)=|"
		<< right.getGradeSign() << "|"
		<< right.getGradeExecute() << "|" 
		<< " sign place ( ";
		if (right.getSigned())
	os		<< "X";
		else
	os 		<< " ";
	os	<< " )]";
	return os;
}
