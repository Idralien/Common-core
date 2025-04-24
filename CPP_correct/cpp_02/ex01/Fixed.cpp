/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:08:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 17:10:21 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
  	this->_value = rhs.getRawBits();
  return *this;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
  return this->_value;
}

void Fixed::setRawBits(int const raw)
{
  this->_value = raw;
}

float Fixed::toFloat() const
{
  return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
  return this->_value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
  os << fixed.toFloat();
  return os;
}
