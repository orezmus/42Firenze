#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedPoint_;
	static const int bits_;

public:
	Fixed();
	Fixed(const int x);
	Fixed(const float y);
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed &copy);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& num) const;
	bool operator<(const Fixed& num) const;
	bool operator>=(const Fixed& num) const;
	bool operator<=(const Fixed& num) const;
	bool operator==(const Fixed& num) const;
	bool operator!=(const Fixed& num) const;

	Fixed operator+(const Fixed& num) const;
	Fixed operator-(const Fixed& num) const;
	Fixed operator*(const Fixed& num) const;
	Fixed operator/(const Fixed& num) const;
	
	Fixed operator++(int);
	Fixed& operator++();
	Fixed operator--(int);
	Fixed& operator--();

	static Fixed& min(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed & f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
