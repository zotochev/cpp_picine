#include <iostream>
#include <string>

int	main()
{
	std::string line = "HI THIS IS BRAIN";
	std::string	* line_p = &line;
	std::string & line_r = line;

	std::cout << "Pointer:	"		<< *line_p << std::endl;
	std::cout << "Reference:	"	<< line_r << std::endl;
	return 0;
}
