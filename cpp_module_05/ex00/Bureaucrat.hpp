#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		Bureaucrat();
		std::string	const	_name;
		int					_grade;
	
	public:
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & other);
		~Bureaucrat();

		Bureaucrat &		operator=(Bureaucrat const & right);

		std::string			getName() const;
		int					getGrade() const;

		void				incGrade();
		void				decGrade();

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

		static int	gratest_grade;
		static int	lowest_grade;
};

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & right);

#endif
