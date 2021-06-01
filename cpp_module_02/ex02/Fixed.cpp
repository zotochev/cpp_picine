#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed() : value(0)
{}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int number) : value(number << fraction)
{}

Fixed::Fixed(const float number) : value(roundf(number * (1 << fraction)))
{}

Fixed::~Fixed()
{}

//
//	GETTERS SETTERS
//

int Fixed::getRawBits() const
{
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

//
//	MEMBER FUNCTIONS
//

int		Fixed::toInt() const
{
	return (int)toFloat();
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
	value = other.getRawBits();
	return *this;
}

bool	Fixed::operator > (Fixed const & other) const
{
	return this->getRawBits() > other.getRawBits();
}
bool	Fixed::operator < (Fixed const & other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool	Fixed::operator <= (Fixed const & other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool	Fixed::operator >= (Fixed const & other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool	Fixed::operator == (Fixed const & other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool	Fixed::operator != (Fixed const & other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator + (Fixed const & other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed	Fixed::operator - (Fixed const & other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed	Fixed::operator * (Fixed const & other) const
{
	Fixed	result;
	long	temp;

	temp = (long)this->getRawBits() * (long)other.getRawBits();
	temp += (1 << (Fixed::fraction - 1));
	result.setRawBits(result.sat(temp >> Fixed::fraction));
	return result;
}

Fixed	Fixed::operator / (Fixed const & other) const
{
	Fixed	result;
	long	temp = this->getRawBits() << Fixed::fraction;

	if ((temp >= 0 && other.getRawBits() >= 0)
		|| (temp < 0 && other.getRawBits() < 0))
		temp += other.getRawBits() / 2;
	else
		temp -= other.getRawBits() / 2;

	result.setRawBits((int)(temp / other.getRawBits()));
	return result;
}

int	Fixed::sat(long x)
{
	if (x > 0x80000000)
		return 0x7FFFFFFF;
	else if (x < -0x7FFFFFFF)
		return -0x7FFFFFFF;
	else
		return (int)x;
}

Fixed &	Fixed::operator ++ ()		//	preincrement
{
	value++;
	return *this;
}

Fixed	Fixed::operator ++ (int)	//	postincrement
{
	Fixed	result(*this);

	++*this;
	return result;
}

Fixed &	Fixed::operator -- ()
{
	value--;
	return *this;
}

Fixed	Fixed::operator -- (int)
{
	Fixed	result(*this);

	--*this;
	return result;
}

std::ostream &	operator << (std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return o;
}

Fixed &	min(Fixed & a, Fixed & b)
{
	if (a > b)
		return b;
	else
		return a;
}
const Fixed &	min(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return b;
	else
		return a;
}

Fixed &	max(Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed &	max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return a;
	else
		return b;
}

const int Fixed::fraction = 8;
