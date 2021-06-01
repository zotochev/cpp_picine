#include "Contact.hpp"
#include "main.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void	Contact::create_new_contact()
{
	std::string	buffer;

	std::cout << "First name: ";
	std::getline(std::cin, buffer);
	this->set_first_name(buffer);

	if (!std::cin)
		return ;
	std::cout << "Last name: ";
	std::getline(std::cin, buffer);
	this->set_last_name(buffer);

	if (!std::cin)
		return ;
	std::cout << "Nickname: ";
	std::getline(std::cin, buffer);
	this->set_nickname(buffer);

	if (!std::cin)
		return ;
	std::cout << "Login: ";
	std::getline(std::cin, buffer);
	this->set_login(buffer);

	if (!std::cin)
		return ;
	std::cout << "Postal address: ";
	std::getline(std::cin, buffer);
	this->set_postal_address(buffer);

	if (!std::cin)
		return ;
	std::cout << "Email address: ";
	std::getline(std::cin, buffer);
	this->set_email_address(buffer);

	if (!std::cin)
		return ;
	std::cout << "Phone number: ";
	std::getline(std::cin, buffer);
	this->set_phone_number(buffer);

	if (!std::cin)
		return ;
	std::cout << "Birthday date: ";
	std::getline(std::cin, buffer);
	this->set_birthday_date(buffer);

	if (!std::cin)
		return ;
	std::cout << "Favorite meal: ";
	std::getline(std::cin, buffer);
	this->set_favorite_meal(buffer);

	if (!std::cin)
		return ;
	std::cout << "Underwear color: ";
	std::getline(std::cin, buffer);
	this->set_underwear_color(buffer);

	if (!std::cin)
		return ;
	std::cout << "Darkest secret: ";
	std::getline(std::cin, buffer);
	this->set_darkest_secret(buffer);
}

bool	Contact::is_in_contact(const std::string& line) const
{
	if (line == first_name
		|| line == last_name
		|| line == nickname
		|| line == login
		|| line == postal_address
		|| line == email_address
		|| line == phone_number
		|| line == birthday_date
		|| line == favorite_meal
		|| line == underwear_color
		|| line == darkest_secret
		)
		return true;
	else
		return false;
}

void	Contact::show()
{
	std::cout << "First name:\t\t";
	std::cout << this->first_name << std::endl;
	std::cout << "Last name:\t\t";
	std::cout << this->last_name << std::endl;
	std::cout << "Nickname:\t\t";
	std::cout << this->nickname << std::endl;
	std::cout << "Login:\t\t\t";
	std::cout << this->login << std::endl;
	std::cout << "Postal address:\t\t";
	std::cout << this->postal_address << std::endl;
	std::cout << "Email address:\t\t";
	std::cout << this->email_address << std::endl;
	std::cout << "Phone number:\t\t";
	std::cout << this->phone_number << std::endl;
	std::cout << "Birthday date:\t\t";
	std::cout << this->birthday_date << std::endl;
	std::cout << "Favorite meal:\t\t";
	std::cout << this->favorite_meal << std::endl;
	std::cout << "Underwear color:\t";
	std::cout << this->underwear_color << std::endl;
	std::cout << "Darkest secret:\t\t";
	std::cout << this->darkest_secret << std::endl;
}

/*
**	SETTERS
*/

void	Contact::set_first_name(const std::string& first_name_)
{
	this->first_name = first_name_;
}

void	Contact::set_last_name(const std::string& last_name_)
{
	this->last_name = last_name_;
}

void	Contact::set_nickname(const std::string& nickname_)
{
	this->nickname = nickname_;
}

void	Contact::set_login(const std::string& login_)
{
	this->login = login_;
}

void	Contact::set_postal_address(const std::string& postal_address_)
{
	this->postal_address = postal_address_;
}

void	Contact::set_email_address(const std::string& email_address_)
{
	this->email_address = email_address_;
}

void	Contact::set_phone_number(const std::string& phone_number_)
{
	this->phone_number = phone_number_;
}

void	Contact::set_birthday_date(const std::string& birth_date_)
{
	this->birthday_date = birth_date_;
}

void	Contact::set_favorite_meal(const std::string& favorite_meal_)
{
	this->favorite_meal = favorite_meal_;
}

void	Contact::set_underwear_color(const std::string& underwear_color_)
{
	this->underwear_color = underwear_color_;
}

void	Contact::set_darkest_secret(const std::string& darkest_secret_)
{
	this->darkest_secret = darkest_secret_;
}

/*
**	GETTERS
*/

std::string	Contact::get_first_name() const
{
	return this->first_name;
}

std::string	Contact::get_last_name() const
{
	return this->last_name;
}

std::string Contact::get_nickname() const
{
	return this->nickname;
}

std::string Contact::get_login() const
{
	return this->login;
}

std::string Contact::get_postal_address() const
{
	return this->postal_address;
}

std::string Contact::get_email_address() const
{
	return this->email_address;
}

std::string Contact::get_phone_number() const
{
	return this->phone_number;
}

std::string Contact::get_birthday_date() const
{
	return this->birthday_date;
}

std::string Contact::get_favorite_meal() const
{
	return this->favorite_meal;
}

std::string Contact::get_underwear_color() const
{
	return this->underwear_color;
}

std::string Contact::get_darkest_secret() const
{
	return this->darkest_secret;
}
