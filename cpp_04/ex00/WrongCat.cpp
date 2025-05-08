/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:28:00 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 19:38:06 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
  type = "Wrong Cat";
  std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
  WrongAnimal::operator=(other);
  std::cout << "WrongCat assignment operator called" << std::endl;
  return *this;
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
  std::cout << "Wrong meow!" << std::endl;
}
