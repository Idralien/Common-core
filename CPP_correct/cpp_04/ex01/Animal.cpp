/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:20:19 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 15:28:01 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
  std::cout << "Default Animal constructor" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
  std::cout << "Copy constructor Animal" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
  if (this != &rhs)
  {
    type = rhs.type;
  }
  std::cout << "Animal copy assignment operator" << std::endl;
  return *this;
}

Animal::~Animal()
{
  std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
  return type;
}

void  Animal::makeSound() const
{
  std::cout << "Animal sound" << std::endl;
}
