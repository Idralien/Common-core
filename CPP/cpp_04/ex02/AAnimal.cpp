/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:20:19 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:43:22 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
  std::cout << "Animal base constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
  std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
  std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &rhs)
  {
    type = rhs.type;
  }
  return *this;
}

std::string AAnimal::getType() const
{
  return type;
}
