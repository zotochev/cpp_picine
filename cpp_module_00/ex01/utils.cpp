#include "main.hpp"

std::string	crop_string(std::string line, unsigned long crop_size)
{
	if (line.length() > crop_size)
		return line.substr(0, crop_size - 1) + ".";
	else
		return line;
}

bool		is_number(std::string line)
{
	unsigned long	count;

	count = 0;
	if (line.length() == 0)
		return false;
	while (line.length() > count)
	{
		if (!std::isdigit(line[count]))
			return false;
		count++;
	}
	return true;
}