#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private :
	int fixed_val;
	static const int frac_bit;
public :
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int n);
	Fixed(const float nf);
	Fixed& operator=(const Fixed &obj);
	~Fixed();

	int	getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif