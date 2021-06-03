#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

void	check_dead(Enemy** a)
{
	if (*a != nullptr && (*a)->getHP() == 0)
	{
		delete *a;
		*a = nullptr;
	}
}

int main()
{
	Character*	me = new Character("me");
	std::cout << *me;
	Enemy*		b = new RadScorpion();
	Enemy*		c = new SuperMutant();
	AWeapon*	pr = new PlasmaRifle();
	AWeapon*	pf = new PowerFist();


	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;

	me->attack(b);
	check_dead(&b);

	std::cout << *me;

	me->attack(b);
	check_dead(&b);

	std::cout << *me;

	me->attack(c);
	check_dead(&c);

	std::cout << *me;

	me->attack(c);
	check_dead(&c);

	std::cout << *me;

	me->attack(c);
	check_dead(&c);

	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();

	me->attack(c);
	check_dead(&c);

	me->attack(c);
	check_dead(&c);

	me->attack(c);
	check_dead(&c);

	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();

	me->attack(c);
	check_dead(&c);

	me->attack(c);
	check_dead(&c);

	me->attack(c);
	check_dead(&c);

	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();

	me->attack(c);
	check_dead(&c);

	me->attack(c);
	check_dead(&c);

	me->attack(c);
	check_dead(&c);

	std::cout << *me;

	delete me;
	delete pr;
	delete pf;	
	if (b != nullptr)
		delete b;
	if (c != nullptr)
		delete c;
	return 0;
}
