#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define PHONEBOOK_SIZE 8
# define PHONEBOOK_FIELD 10

std::string	crop_string(std::string line, unsigned long crop_size);
bool		is_number(std::string line);

#endif
