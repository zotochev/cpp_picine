#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::srand(std::time(nullptr));

	std::vector<int> test;

	int	num;
	for (int i = 0; i < 20; i++)
		test.push_back(rand() % 10);
	try
	{
		num = rand() % 10;
		std::cout << *easyfind(test, num) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found "<< num << std::endl;
	}

	std::list<int> test2;
	for (int i = -10; i <= 10; i++)
		test2.push_back(i * (rand() % 3));
	try
	{
		std::cout << *easyfind(test2, 0) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found 0" << std::endl;
	}
	try
	{
		std::cout << *easyfind(test2, -7) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found -7" << std::endl;
	}
	return (0);
}
