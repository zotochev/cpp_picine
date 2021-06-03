#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	ISpaceMarine* bob1 = new TacticalMarine;
	ISpaceMarine* jim1 = new AssaultTerminator;
	ISpaceMarine* bob2 = new TacticalMarine;
	ISpaceMarine* jim2 = new AssaultTerminator;
	ISquad* vlc = new Squad;
	

	std::cout << "---" << std::endl;
	ISpaceMarine* cur_test = vlc->getUnit(9);
	std::cout << cur_test << std::endl;
	std::cout << "---" << std::endl;

	vlc->push(bob1);
	vlc->push(jim1);
	vlc->push(bob2);
	vlc->push(jim2);
	
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		std::cout << "* " << i << " *" << std::endl;
		if (nullptr != vlc->getUnit(i))
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
	}


	std::cout << "-----new-------" << std::endl;
	ISquad* vlc_copy = new Squad(*((Squad*)vlc));
	std::cout << "---------------" << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		std::cout << "* " << i << " *" << std::endl;
		if (nullptr != vlc_copy->getUnit(i))
		{
			ISpaceMarine* cur_copy = vlc_copy->getUnit(i);
			cur_copy->battleCry();
			cur_copy->rangedAttack();
			cur_copy->meleeAttack();
		}
	}

	std::cout << "-----new-------" << std::endl;
	ISquad* vlc_asg = new Squad;

	*((Squad*)vlc_asg) = *((Squad*)vlc);
	std::cout << "---------------" << std::endl;

	delete vlc;
	std::cout << "//////////" << std::endl;
	delete vlc_copy;
	std::cout << "//////////" << std::endl;
	delete vlc_asg;
	std::cout << "//////////" << std::endl;
	return 0;
}
