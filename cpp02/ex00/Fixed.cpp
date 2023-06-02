#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		setRawBits(obj.getRawBits());
	return (*this); 
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_val);
}
void Fixed::setRawBits(int const raw)
{
	this->fixed_val = raw;
}