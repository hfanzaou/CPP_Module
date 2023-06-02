#include "Fixed.hpp"
#include "cmath"

const int	Fixed::frac_bit = 8;

Fixed::Fixed() : fixed_val(0)
{
	std::cout << "Default constructor called" << std::endl;
} 

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int n) : fixed_val(n * (1 << frac_bit))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nf) : fixed_val(roundf(nf * (1 << frac_bit)))
{
	std::cout << "Float constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		setRawBits(obj.getRawBits());
	return (*this); 
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

int Fixed::toInt( void ) const
{
	return (this->fixed_val / (1 << frac_bit));
}

float Fixed::toFloat( void ) const
{
	return (this->fixed_val / (float)(1 << frac_bit));
}
int Fixed::getRawBits(void) const 
{
	return (this->fixed_val);
}
void Fixed::setRawBits(int const raw)
{
	this->fixed_val = raw;
}