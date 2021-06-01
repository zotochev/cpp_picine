#include "Phonebook.hpp"
#include "main.hpp"

Phonebook::Phonebook()
{
	this->contacts_present = PHONEBOOK_SIZE;
	std::cout << "Welcome to a crappy awesome phonebook";
	std::cout << std::endl;
	std::cout << "Input one of the following commands: ADD, SEARCH, EXIT";
	std::cout << std::endl;
}

Phonebook::~Phonebook()
{}

bool	Phonebook::add_()
{
	Contact	new_contact;

	if (this->contacts_present > 0)
	{
		new_contact.create_new_contact();
		this->contacts[PHONEBOOK_SIZE - this->contacts_present] = new_contact;
		this->contacts_present--;
	}
	else
	{
		std::cout << "There is no more space in the Phonebook to add a contact";
		std::cout << std::endl;
	}
	return true;
}

void	Phonebook::draw_line()
{
	int count;

	count = 0;
	std::cout << "+";
	while (PHONEBOOK_FIELD * 4 + 3 > count)
	{
		std::cout << "-";
		count++;
	}
	std::cout << "+";
	std::cout << std::endl;
}

void	Phonebook::show_phonebook_header()
{
	this->draw_line();
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << "Index";
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << "First name";
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << "Last name";
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << "Nickname";
	std::cout << "|" << std::endl;
	this->draw_line();
}

void	Phonebook::show_contact(int count)
{
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << count;
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << crop_string(this->contacts[count].get_first_name(), PHONEBOOK_FIELD);
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << crop_string(this->contacts[count].get_last_name(), PHONEBOOK_FIELD);
	std::cout << "|" << std::setw(PHONEBOOK_FIELD);
	std::cout << crop_string(this->contacts[count].get_nickname(), PHONEBOOK_FIELD);
	std::cout << "|" << std::endl;
}

bool	Phonebook::search_()
{
	int			count;
	int			index;
	std::string	buffer;

	count = 0;
	this->show_phonebook_header();
	while (count < PHONEBOOK_SIZE - this->contacts_present)
	{
		this->show_contact(count);
		count++;
	}
	this->draw_line();
	std::cout << "Input index of a contact: ";
	std::getline(std::cin, buffer);
	if (is_number(buffer))
	{
		index = std::atoi(buffer.c_str());
		if (0 <= index && PHONEBOOK_SIZE - this->contacts_present > index)
			this->contacts[std::atoi(buffer.c_str())].show();
		else
			std::cout << "No contact with such index" << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
	return true;
}

bool	Phonebook::exit_()
{
	return false;
}

void	Phonebook::process()
{
	int			state;
	std::string	buffer;

	state = true;
	while (state)
	{
		if (!std::cin)
			break ;
		std::cout << "Input a command: ";
		std::getline(std::cin, buffer);
		if ("ADD" == buffer)
			state = this->add_();
		else if ("SEARCH" == buffer)
			state = this->search_();
		else if ("EXIT" == buffer)
			state = this->exit_();
	}
}