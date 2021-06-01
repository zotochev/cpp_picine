#include <fstream>
#include <iostream>
#include <string>

unsigned	ft_sed(char *file, char *from, char *to)
{
	std::string		text;
	unsigned		index;
	std::ifstream	file_in(file);
	std::ofstream	file_out(std::string(file) + ".replace");
	int				from_length;
	int				to_length;

    if (file_in.is_open() && file_out.is_open())
    {
        from_length = std::string(from).length();
        to_length = std::string(to).length();
        while (from_length > 0)
        {
			std::getline(file_in, text);
            while (std::string::npos != (text.find(from, index)))
            {
                text.replace(index = text.find(from, index), from_length, to);
                index += to_length;
            }
            index = 0;
            file_out << text;
            if (!file_in.eof())
				file_out << std::endl;
            else
            	break ;
        }
        file_in.close();
        file_out.close();
    }
	else
	{
		std::cout << "Failed to open a file" << std::endl;
		return 1;
	}
	return 0;
}

Все виртуальные методы базового класса являются виртуальными и для производных классов.
Виртуальные методы могут вызывать невиртуальные методы.
Виртуальные методы могут быть константными.

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc == 4)
	{
		if (0 != ft_sed(argv[1], argv[2], argv[3]))
			return 1;
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return 0;
}
