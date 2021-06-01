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

	Fixed & operator = (Fixed const & other);

	bool	operator > (Fixed const & other) const;
	bool	operator < (Fixed const & other) const;
	bool	operator <= (Fixed const & other) const;
	bool	operator >= (Fixed const & other) const;
	bool	operator == (Fixed const & other) const;
	bool	operator != (Fixed const & other) const;

	Fixed	operator + (Fixed const & other) const;
	Fixed	operator - (Fixed const & other) const;
	Fixed	operator * (Fixed const & other) const;
	Fixed	operator / (Fixed const & other) const;

	Fixed &	operator ++ ();		//	preincrement
	Fixed	operator ++ (int);	//	postincrement

	Fixed &	operator -- ();
	Fixed	operator -- (int);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;


private:
	int					value;
	static const int	fraction;
	int					sat(long x);
};

	Fixed &	min(Fixed & a, Fixed & b);
	const Fixed &	min(const Fixed & a, const Fixed & b);
	Fixed &	max(Fixed & a, Fixed & b);
	const Fixed &	max(const Fixed & a, const Fixed & b);

	std::ostream &	operator<<(std::ostream & o, Fixed const & i);


#endif
