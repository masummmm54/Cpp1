#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
	private:
	int					fixed_point;
	static const int	fractionalBits = 8;

	public:
	Fixed();
	Fixed(int const i);
	Fixed(float const i);
	Fixed(const Fixed &p);
	Fixed& operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
