#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion()
{}

ScalarConversion::ScalarConversion(std::string const & literal)
	: _literal(literal)
	, _char(0)
	, _char_status("~")
	, _int(0)
	, _int_status("~")
	, _float(0)
	, _float_status("~")
	, _double(0)
	, _double_status("~")
{
	isLiteralValidChar();
	isLiteralValidInt();
	isLiteralValidFloat();
	isLiteralValidDouble();
}

ScalarConversion::ScalarConversion(ScalarConversion const & other)
	: _literal(other.getLiteral())
{}

ScalarConversion::~ScalarConversion()
{}

ScalarConversion &	ScalarConversion::operator=(ScalarConversion const & right)
{
	if (this != &right)
	{
		_literal = right.getLiteral();
	}
	return *this;
}

std::string	ScalarConversion::getLiteral() const	{ return _literal; }

void	ScalarConversion::isLiteralValidChar()
{
	try
	{
		if (_literal.length() == 1 && !std::isdigit(_literal[0]))
		{
			_char = static_cast<char>(_literal[0]);
		}
		else if (std::stoi(_literal) >= 0 && std::stoi(_literal) <= 127)
		{
			_char = static_cast<char>(std::stoi(_literal));
		}
		else
			throw std::invalid_argument("");

		if (std::isprint(_char))
			_char_status = "ok";
		else
			_char_status = "non displayable";
	}
	catch(std::exception &e)
	{
		_char_status = "impossible";
	}
}

void	ScalarConversion::isLiteralValidInt()
{
	try
	{
		if (_literal.length() == 1 && !std::isdigit(_literal[0]) && std::isprint(_literal[0]))
			_int = static_cast<int>(_literal[0]);
		else
			_int = static_cast<int>(std::stoi(_literal));
		_int_status = "ok";
	}
	catch(std::exception &e)
	{
		_int_status = "impossible";
	}
}

void	ScalarConversion::isLiteralValidFloat()
{
	try
	{
		if (_literal.length() == 1 && !std::isdigit(_literal[0]) && std::isprint(_literal[0]))
			_float = static_cast<float>(_literal[0]);
		else
			_float = static_cast<float>(std::stof(_literal));
		_float_status = "ok";
	}
	catch(std::exception &e)
	{
		_float_status = "impossible";
	}
}

void	ScalarConversion::isLiteralValidDouble()
{
	try
	{
		if (_literal.length() == 1 && !std::isdigit(_literal[0]) && std::isprint(_literal[0]))
			_double = static_cast<double>(_literal[0]);
		else
			_double = static_cast<double>(std::stod(_literal));
		_double_status = "ok";
	}
	catch(std::exception &e)
	{
		_double_status = "impossible";
	}
}

void	ScalarConversion::printChar() const
{
	std::cout << "char: ";
	if (_char_status == "ok")
		std::cout << _char;
	else
		std::cout << _char_status;
	std::cout << std::endl;
}

void	ScalarConversion::printInt() const
{
	std::cout << "int: ";
	if (_int_status == "ok")
		std::cout << _int;
	else
		std::cout << _int_status;
	std::cout << std::endl;
}

void	ScalarConversion::printFloat() const
{
	std::cout << "float: ";
	if (_float_status == "ok")
	{
		std::cout << _float;
		if (static_cast<int>(_float) - _float == 0.f && _float < 1000000.f)
			std::cout << ".0";
		std::cout << "f";
	}
	else
		std::cout << _float_status;
	std::cout << std::endl;
}

void	ScalarConversion::printDouble() const
{
	std::cout << "double: ";
	if (_double_status == "ok")
	{
		std::cout << _double;
		if (static_cast<int>(_double) - _double == 0. && _float < 1000000.)
			std::cout << ".0";
	}
	else
		std::cout << _double_status;
	std::cout << std::endl;
}

void	ScalarConversion::print() const
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}


