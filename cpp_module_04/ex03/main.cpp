#include <iostream>

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Ground.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ground());

	std::cout << *src << std::endl;
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	tmp->use(*me);
	src->learnMateria(tmp);
	me->equip(tmp);
	tmp = src->createMateria("ground");
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	std::cout << *me << std::endl;

	ICharacter* bob = new Character("bob");
	ICharacter* bob_clone = new Character(*((Character *)bob));
	ICharacter* bob_asg = new Character("boooob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(9, *bob);

	std::cout << *me << std::endl;
	std::cout << *bob << std::endl;
	IMateriaSource* src_test(src);
	std::cout << *src_test << std::endl;

	std::cout << "+++++++++++++++++++++" << std::endl;
   	*((Character*)bob_asg) = *((Character*)me);
	std::cout << *bob_asg << std::endl;
	std::cout << "+++++++++++++++++++++" << std::endl;
	delete bob;
	delete bob_clone;
	delete bob_asg;
	delete me;
	delete src;

	std::cout << "+++++++++++++++++++++" << std::endl;
	return 0;
}
