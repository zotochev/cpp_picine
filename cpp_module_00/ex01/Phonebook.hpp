#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class	Phonebook
{
	public:
		Phonebook();
		~Phonebook();

		void		process();

	private:
		bool		add_();
		bool		search_();
		bool		exit_();
		int			contacts_present;
		Contact		contacts[PHONEBOOK_SIZE];
		void		show_phonebook_header();
		void		draw_line();
		void		show_contact(int count);
};

#endif
