#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int number) : value(number << (fraction + 0))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : value(roundf(number * (1 << fraction)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//
//	GETTERS SETTERS
//

int Fixed::getRawBits() const
{
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

//
//	MEMBER FUNCTIONS
//

int		Fixed::toInt() const
{
	return getRawBits() >> fraction;
}

float	Fixed::toFloat() const
{
	return (float)getRawBits() / (1 << fraction);
}

//
//	OPERATORS OVERLOAD
//

Fixed &	Fixed::operator = (Fixed const & other)
{
	std::cout << "Assignation operator called" << std::endl;
	value = other.getRawBits();
	return *this;
}

std::ostream &	operator << (std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return o;
}

const int Fixed::fraction = 8;
