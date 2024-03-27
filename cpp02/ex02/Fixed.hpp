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
	~Fixed();
	Fixed(const Fixed &p);
	Fixed& operator=(const Fixed &other);
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	//comparison
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	//arithmetics
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	// increment/decrement 
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	//overloaded member functions
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a,const Fixed &b);
	static const Fixed &max(const Fixed &a,const Fixed &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
