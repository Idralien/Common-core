/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:27:12 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 17:28:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed& Fixed::operator=(const Fixed& rhs)
{
  if (this != &rhs)
    this->_value = rhs.getRawBits();
  return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits() const { return this->_value; }
void Fixed::setRawBits(int const raw) { this->_value = raw; }

float Fixed::toFloat() const { return (float)_value / (1 << _fractionalBits); }
int Fixed::toInt() const { return _value >> _fractionalBits; }

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed& rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed& rhs) const { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed& rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed& rhs) const { return Fixed(this->toFloat() / rhs.toFloat()); }

// Increment/decrement operators
Fixed& Fixed::operator++()
{
  _value += 1;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed temp(*this);
  operator++();
  return temp;
}

Fixed& Fixed::operator--()
{
  _value -= 1;
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed temp(*this);
  operator--();
  return temp;
}

// Min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
