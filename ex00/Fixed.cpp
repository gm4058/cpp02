#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{ 
    std::cout << "Default constructor called" << std::endl;    
    this->fpValue = 0; 
}

Fixed::Fixed(const Fixed& other)
{ 
    std::cout << "Copy constructor called" << std::endl;
    this->fpValue = other.fpValue; 
}

Fixed& Fixed::operator = (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fpValue = other.fpValue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member fuc called" << std::endl;
    return this->fpValue;
}

void Fixed::setRawBits(int raw)
{
    std::cout << "setRawBits member fuc called" << std::endl;
    this->fpValue = raw;
}

