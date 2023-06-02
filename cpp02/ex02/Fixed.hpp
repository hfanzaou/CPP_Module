#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {

private :
	int fixed_val;
	static const int frac_bit;
public :
	//constructors
	Fixed();
	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float);

	//destructor
	~Fixed();

	//operator_overloads
	Fixed&	operator=(const Fixed &);
	Fixed	operator+(const Fixed &) const;
	Fixed	operator-(const Fixed &) const;
	Fixed	operator*(const Fixed &) const;
	Fixed	operator/(const Fixed &) const;
	Fixed	operator++(int);
	Fixed 	operator--(int);
	Fixed&	operator++();
	Fixed&	operator--();
	bool	operator==(const Fixed &) const;
	bool	operator>(const Fixed &) const;
	bool	operator<(const Fixed &) const;
	bool	operator>=(const Fixed &) const;
	bool	operator<=(const Fixed &) const;
	bool	operator!=(const Fixed &) const;

	//member_functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	//static_m_functions
	static Fixed&		min(Fixed &, Fixed &);
	static Fixed&		max(Fixed &, Fixed &);
	static const Fixed&	min(const Fixed &, const Fixed &);
	static const Fixed&	max(const Fixed &, const Fixed &);
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif