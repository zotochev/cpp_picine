#include "Pony.hpp"

#include <string>

void	ponyOnTheStack()
{
	Pony	pony_1;

	pony_1.say();
}

void	ponyOnTheHeap()
{
	Pony	*pony_2;

	pony_2 = new Pony("Mister Bristle", "red", "Hello!");
	pony_2->say();
	delete pony_2;
}


int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return 0;
}
