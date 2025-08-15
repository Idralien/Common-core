/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:32:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 15:38:52 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
  type = "Dog";
  std::cout << "Default Dog constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
  std::cout << "Copy constructor Dog" << std::endl;
}
Dog& Dog::operator=(const Dog& rhs)
{
  Animal::operator=(rhs);
  std::cout << "Copy assignment operator Dog" << std::endl;
  return *this;
}

Dog::~Dog()
{
  std::cout << "Destructor Dog" << std::endl;
}

void  Dog::makeSound() const
{
  std::cout << "Bark" << std::endl;
}
