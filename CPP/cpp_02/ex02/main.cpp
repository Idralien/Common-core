/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:28:50 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 17:29:21 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  
  std::cout << b << std::endl;
  
  std::cout << Fixed::max(a, b) << std::endl;
  
  // Additional tests
  Fixed c(10.5f);
  Fixed d(5.25f);
  
  std::cout << "\nAdditional tests:\n";
  std::cout << "c + d = " << c + d << std::endl;
  std::cout << "c - d = " << c - d << std::endl;
  std::cout << "c * d = " << c * d << std::endl;
  std::cout << "c / d = " << c / d << std::endl;
  
  std::cout << "c > d: " << (c > d) << std::endl;
  std::cout << "c < d: " << (c < d) << std::endl;
  std::cout << "c == d: " << (c == d) << std::endl;
  
  return 0;
}
