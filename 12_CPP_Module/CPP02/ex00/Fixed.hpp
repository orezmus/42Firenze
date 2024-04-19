#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
private:
	int fixedPoint_;
	static const int bits_;

public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
