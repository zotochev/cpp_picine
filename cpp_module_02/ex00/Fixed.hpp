#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
public:
	Fixed();
	Fixed(Fixed const & other);
	~Fixed();

	Fixed & operator=(Fixed const & other);

	int		getRawBits() const;
	void	setRawBits(int const raw);

private:
	int					value;
	static const int	fraction;
};


#endif
