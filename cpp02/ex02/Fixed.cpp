#include "Fixed.hpp"

const int	Fixed::frac_bit = 8;

//constructors
Fixed::Fixed() : fixed_val(0)
{
	std::cout << "Default constructor called" << std::endl;
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

//destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//operator_overloads

//+_-_/_*_=
Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		setRawBits(obj.getRawBits());
	return (*this); 
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed temp(toFloat() * obj.toFloat());
	return (temp);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed temp(toFloat() - obj.toFloat());
	temp.setRawBits(getRawBits() - obj.getRawBits());
	return (temp);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed temp(toFloat() * obj.toFloat());
	return (temp);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed temp(toFloat() / obj.toFloat());
	return (temp);
}

//++_--
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixed_val++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixed_val--;
	return (temp);
}

Fixed& Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator--()
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

//comparisons >,<,>=<=,==,!=
bool Fixed::operator>(const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());	
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());	
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());	
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

//member_functions
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

//static_m_functions
Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() >= obj2.getRawBits())
		return (obj2);
	else
		return (obj1);	
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() >= obj2.getRawBits())
		return (obj1);
	else
		return (obj2);	
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() >= obj2.getRawBits())
		return (obj2);
	else
		return (obj1);
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() >= obj2.getRawBits())
		return (obj1);
	else
		return (obj2);
}