#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const & other);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();

	Fixed & operator=(Fixed const & other);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

private:
	int					value;
	static const int	fraction;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif
