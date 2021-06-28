#include "ScalarConversion.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConversion	a(argv[1]);
		a.print();
	}
	else
	{
		std::cout << "wrong number of arguments" << std::endl;
	}

	return 0;
}
