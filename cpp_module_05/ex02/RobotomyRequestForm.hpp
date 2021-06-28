#ifndef	ROBOTOMY_REQUEST_FORM_HPP 
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <fstream>

#include "Form.hpp"

class RobotomyRequestForm : public Form
{

	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & other);
		~RobotomyRequestForm();
		RobotomyRequestForm &	operator=(RobotomyRequestForm const & right);

		void	action() const;

	private:
		RobotomyRequestForm();
};

#endif
