/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:06:46 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 17:08:00 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
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

	private:
  	int                 _value;
  	static const int    _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
