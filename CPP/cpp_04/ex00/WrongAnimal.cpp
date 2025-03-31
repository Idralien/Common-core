/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:56:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 16:08:33 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
  std::cout << "Default constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
  std::cout << "Copy constructor WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
  if (this != &rhs)
  {
    type = rhs.type;
  }
  std::cout << "Copy assignment operator WrongAnimal" << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "Destructor WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const
{
  return type;
}

void  WrongAnimal::makeSound() const
{
  std::cout << "Roar (Wrong sound)" << std::endl;
}
