/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:20:19 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 19:30:51 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Generic Animal")
{
  std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
  std::cout << "Animal type constructor (" << type << ")" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
  std::cout << "Copy constructor Animal" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
  if (this != &other)
  {
    type = other.type;
  }
  std::cout << "Animal assignment operator" << std::endl;
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
