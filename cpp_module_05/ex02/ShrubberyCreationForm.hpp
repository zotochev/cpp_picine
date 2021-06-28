#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & right);

		void				action() const;
		static std::string	tree;

	private:
		ShrubberyCreationForm();
};

#endif
