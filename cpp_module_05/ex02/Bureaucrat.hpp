#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		Bureaucrat();
		std::string const	_name;
		int					_grade;
	
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & other);
		~Bureaucrat();

		Bureaucrat &		operator=(Bureaucrat const & right);

		std::string			getName() const;
		int					getGrade() const;

		void				signForm(Form & form);
		void				executeForm(Form const & form);

		void				incGrade();
		void				decGrade();

		static int	gratest_grade;
		static int	lowest_grade;
};

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & right);

#endif
