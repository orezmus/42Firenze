#ifndef FIXED_HPP
# define FIXED_HPP

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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
