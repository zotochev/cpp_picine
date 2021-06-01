#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class	Contact
{
	public:
		Contact();
		~Contact();

		void	create_new_contact();
		bool	is_in_contact(const std::string& line) const;
		void	show();
		void	set_first_name(const std::string& first_name_);
		void	set_last_name(const std::string& last_name_);
		void	set_nickname(const std::string& nickname_);
		void	set_login(const std::string& login_);
		void	set_postal_address(const std::string& postal_address_);
		void	set_email_address(const std::string& email_address_);
		void	set_phone_number(const std::string& phone_number_);
		void	set_birthday_date(const std::string& birth_date_);
		void	set_favorite_meal(const std::string& favorite_meal_);
		void	set_underwear_color(const std::string& underwear_color_);
		void	set_darkest_secret(const std::string& darkest_secret_);

		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_login() const;
		std::string get_postal_address() const;
		std::string get_email_address() const;
		std::string get_phone_number() const;
		std::string get_birthday_date() const;
		std::string get_favorite_meal() const;
		std::string get_underwear_color() const;
		std::string get_darkest_secret() const;

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birthday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
};

#endif
