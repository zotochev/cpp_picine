#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		Form();
		std::string	const	_name;
		bool				_signed;
		int const			_grade_sign;
		int const			_grade_execute;
		std::string			_target;
	
	public:

		class GradeTooHighException
			: public Bureaucrat::GradeTooHighException
		{};

		class GradeTooLowException
			: public Bureaucrat::GradeTooLowException
		{};

		Form(std::string const & name, int grade_sign, int grade_execute, std::string const & target);
		Form(Form const & other);
		~Form();

		Form &	operator=(Form const & right);
		bool	beSigned(Bureaucrat const & bureaucrat);
		bool	beExecuted(Bureaucrat const & bureaucrat);

		virtual bool	execute(Bureaucrat const & executor) const;
		virtual void	action() const = 0;

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;
		std::string	getTarget() const;

		void		setName(std::string const & name);
		void		setSigned(bool sign);
		void		setGradeSign(int grade_sign);
		void		setGradeExecute(int grade_execute);
		void		setTarget(std::string const & target);
};

std::ostream &	operator<<(std::ostream & os, Form const & right);

#endif
