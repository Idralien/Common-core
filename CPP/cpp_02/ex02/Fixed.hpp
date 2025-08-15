/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:26:20 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 17:26:59 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
  int                 _value;
  static const int    _fractionalBits = 8;

public:
  Fixed();                            // Default constructor
  Fixed(const int value);             // Int constructor
  Fixed(const float value);           // Float constructor
  Fixed(const Fixed& other);          // Copy constructor
  Fixed& operator=(const Fixed& rhs); // Copy assignment operator
  ~Fixed();                           // Destructor

  int     getRawBits() const;
  void    setRawBits(int const raw);

	float   toFloat() const;
  int     toInt() const;

  // Comparison operators
  bool    operator>(const Fixed& rhs) const;
  bool    operator<(const Fixed& rhs) const;
  bool    operator>=(const Fixed& rhs) const;
  bool    operator<=(const Fixed& rhs) const;
  bool    operator==(const Fixed& rhs) const;
  bool    operator!=(const Fixed& rhs) const;

  // Arithmetic operators
  Fixed   operator+(const Fixed& rhs) const;
  Fixed   operator-(const Fixed& rhs) const;
  Fixed   operator*(const Fixed& rhs) const;
  Fixed   operator/(const Fixed& rhs) const;

  // Increment/decrement operators
  Fixed&  operator++();       // Pre-increment
  Fixed   operator++(int);    // Post-increment
  Fixed&  operator--();       // Pre-decrement
  Fixed   operator--(int);    // Post-decrement

  // Min/max functions
  static Fixed&       min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed&       max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
