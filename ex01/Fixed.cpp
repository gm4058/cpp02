#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fpValue = 0;
}

Fixed::Fixed(const int inum)
{
    std::cout << "Int constructor called" << std::endl;
    this->fpValue = inum << _fractionalBits;
}

Fixed::Fixed(const float fnum)
{
    std::cout << "Float constructor called" << std::endl;
    this->fpValue = roundf(fnum * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fpValue = other.fpValue;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fpValue = other.fpValue;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fpValue = raw;
}

float Fixed::toFloat(void) const
{
    return this->fpValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->fpValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
