#ifndef SCALAR_CONVERSION_HPP
#define SCALAR_CONVERSION_HPP
 
#include <iostream>
#include <string>

class ScalarConversion
{
	private:
		std::string		_literal;

		char			_char;
		std::string		_char_status;

		int				_int;
		std::string		_int_status;

		float			_float;
		std::string		_float_status;

		double			_double;
		std::string		_double_status;

		ScalarConversion();

	public:
		ScalarConversion(ScalarConversion const & other);
		ScalarConversion(std::string const & literal);
		~ScalarConversion();

		ScalarConversion &	operator=(ScalarConversion const & right);

		std::string	getLiteral() const;

		void	isLiteralValidChar();
		void	isLiteralValidInt();
		void	isLiteralValidFloat();
		void	isLiteralValidDouble();

		void	printChar() const;
		void	printInt() const;
		void	printFloat() const;
		void	printDouble() const;

		void	print() const;
};

#endif
