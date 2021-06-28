#include <iostream>
#include <iomanip>
#include "Array.hpp"

int main()
{
	{
		char buffer[] = "abcdefghij";

		Array <char>       char_array(10);
		Array <int>        int_array(10);
		Array <float>      float_array(10);
		Array <double>     double_array(10);

		for (int i = 0; i < 10; i++) { char_array[i] = buffer[i]; }
		for (int i = 0; i < 10; i++) { int_array[i] = buffer[i]; }
		for (int i = 0; i < 10; i++) { float_array[i] = buffer[i]; }
		for (int i = 0; i < 10; i++) { double_array[i] = buffer[i]; }

		std::cout << "* * *" << std::endl;
		std::cout << "char" << std::endl << std::endl;
		std::cout <<  char_array    << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "int" << std::endl << std::endl;
		std::cout <<  int_array     << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "float" << std::endl << std::endl;
		std::cout <<  float_array   << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "double" << std::endl << std::endl;
		std::cout <<  double_array  << std::endl;

	}

	{
		Array <char>  a1;
		Array <int>   a2(10);
		Array <int>   a3(a2);

		Array <float> a4(10);
		Array <float> a5 = a4;

		std::cout << "* * *" << std::endl;
		std::cout << "Array #a1 :: char" << std::endl << std::endl;
		std::cout <<  a1  << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "Array #a2 :: int" << std::endl << std::endl;
		std::cout <<  a2  << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "Array #a3 :: int" << std::endl << std::endl;
		std::cout <<  a3  << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "Array #a4 :: float" << std::endl << std::endl;
		std::cout <<  a4  << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "Array #a5 :: float" << std::endl << std::endl;
		std::cout <<  a5  << std::endl;

		std::cout << "* * *" << std::endl;
		std::cout << "a1 size " << a1.size() << std::endl;
		std::cout << "out of index access try a1[0] :: char" << std::endl << std::endl;

		try {
			std::cout << a1[0] << std::endl;
		} catch ( std::exception & e ) {
			std::cout << e.what() << std::endl << std::endl;
		}

		std::cout << "* * *" << std::endl;
		std::cout << "a4 size " << a4.size() << std::endl;
		std::cout << "out of index access try a4[11] :: float" << std::endl << std::endl;

		try {
			std::cout << a4[11] << std::endl;
		} catch ( std::exception & e ) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}

	return (0);
}
