#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class Form
{
	private:
		Form();
		std::string const	_name;
		bool				_signed;
		int const			_grade_sign;
		int const			_grade_execute;
	
	public:

		class GradeTooHighException
			: public Bureaucrat::GradeTooHighException
		{};

		class GradeTooLowException
			: public Bureaucrat::GradeTooLowException
		{};

		Form(Form const & other);
		Form(std::string const & name, int grade_sign, int grade_execute);
		~Form();

		Form &	operator=(Form const & right);
		bool	beSigned(Bureaucrat const & bureaucrat);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

};

std::ostream &	operator<<(std::ostream & os, Form const & right);

#endif
