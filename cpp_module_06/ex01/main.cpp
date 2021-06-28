#include <iostream>

struct Data
{
	int				num;
	std::string		sp_1;
	std::string		sp_2;	
};

std::string	random_string(int seed)
{
	std::srand(time(NULL) * seed);
	std::string	result;
	char		c;

	result.reserve(10);
	for (int i = 0; i < 10; i++)
	{
		while (1)
		{
			c = rand() & 127;
			if (std::isprint(c))
				break ;
		}
		result += c;
	}
	return result;
}


void	*serialize()
{
	std::srand(time(NULL) * 123);

	char			*raw = new char[52];
	std::string		a = random_string(12);
	int				b = rand();
	std::string		c = random_string(32);
	char			*ptr = nullptr;

	std::cout << "-------generated values-------" << std::endl;
	std::cout << "string 1:	" << a << std::endl;
	std::cout << "number:		" << b << std::endl;
	std::cout << "string 2:	" << c << std::endl;
	std::cout << "------------------------------" << std::endl;


	ptr = raw;
	memcpy(ptr, &a, 24);

	ptr = reinterpret_cast<char *>(raw) + 24;
	memcpy(ptr, &b, 4);

	ptr = reinterpret_cast<char *>(raw) + 28;
	memcpy(ptr, &c, 24);

	return reinterpret_cast<void *>(raw);
}

Data	*deserialize(void *raw)
{
	Data	*result = new Data;
	void	*ptr;

	ptr = reinterpret_cast<char *>(raw);
	result->sp_1 = *(reinterpret_cast<std::string*>(ptr));

	ptr = reinterpret_cast<char *>(raw) + 24;
	result->num = *(reinterpret_cast<int *>(ptr));

	ptr = reinterpret_cast<char *>(raw) + 28;
	result->sp_2 = *(reinterpret_cast<std::string*>(ptr));

	return result;
}


int	main()
{
	void	*v = nullptr;
	Data	*d = nullptr;

	v = serialize();
	d = deserialize(v);
	
	if (d && v)
	{
		std::cout << "----deserialization result----" << std::endl;
		std::cout << "string 1:	" << d->sp_1 << std::endl;
		std::cout << "number:		" << d->num << std::endl;
		std::cout << "string 2:	" << d->sp_2 << std::endl;
		std::cout << "------------------------------" << std::endl;

		delete d;
	}
	return 0;
}
