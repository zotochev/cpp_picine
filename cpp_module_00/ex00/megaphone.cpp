#include <iostream>
#include <string>

std::string string_to_upper(std::string line)
{
	unsigned long	count;

	count = 0;
	while (count < line.length())
	{
		line[count] = std::toupper(line[count]);
		++count;
	}
	return line;
}

int	main(int argc, char **argv)
{
	int	count;

	count = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (count < argc)
		{
			std::cout << string_to_upper(std::string(argv[count]));
			++count;
		}
		std::cout << std::endl;
	}
	return 0;
}
