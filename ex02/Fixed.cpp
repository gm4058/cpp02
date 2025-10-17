#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    // std::cout << "Default constructor called" << std::endl;
    this->fpValue = 0;
}

Fixed::Fixed(const int inum) {
    // std::cout << "Int constructor called" << std::endl;
    this->fpValue = inum << _fractionalBits;
}

Fixed::Fixed(const float fnum) {
    // std::cout << "Float constructor called" << std::endl;
    this->fpValue = roundf(fnum * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    this->fpValue = other.getRawBits();
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}





int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->fpValue;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->fpValue = raw;
}





float Fixed::toFloat(void) const { return this->fpValue / (float)(1 << _fractionalBits); }

int Fixed::toInt(void) const { return this->fpValue >> _fractionalBits; }





Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fpValue = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& other) const { return this->fpValue > other.getRawBits(); }
bool Fixed::operator<(const Fixed& other) const { return this->fpValue < other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const { return this->fpValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const { return this->fpValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const { return this->fpValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const { return this->fpValue != other.getRawBits(); }





Fixed Fixed::operator+(const Fixed& other) const { 
    Fixed result;
    result.setRawBits(this->fpValue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->fpValue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long tmp = (long)this->fpValue * (long)other.getRawBits();
    result.setRawBits(tmp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.getRawBits() == 0) {
        std::cerr << "Error : Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    long tmp = ((long)this->fpValue << _fractionalBits) / other.getRawBits();
    result.setRawBits(tmp);
    return result;
}






Fixed& Fixed::operator++() {
    this->fpValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->fpValue += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    this->fpValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->fpValue -= 1;
    return temp;
}




Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a.getRawBits() > b.getRawBits() ? a : b;
}





std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
