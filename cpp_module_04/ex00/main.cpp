#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Peasant.hpp"

int	main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Peasant sam("Sam");
	
	std::cout << robert << jim << joe << sam;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(sam);
	return 0;
}
