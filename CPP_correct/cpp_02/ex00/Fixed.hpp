/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:57:45 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 16:58:36 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int                 _value;
  static const int    _fractionalBits = 8;

public:
  Fixed();                            // Default constructor
  Fixed(const Fixed& other);          // Copy constructor
  Fixed& operator=(const Fixed& rhs); // Copy assignment operator
  ~Fixed();                           // Destructor

  int     getRawBits() const;
  void    setRawBits(int const raw);
};

#endif
