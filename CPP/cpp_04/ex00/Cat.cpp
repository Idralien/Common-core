/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:42:07 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 15:52:14 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
  type = "Cat";
  std::cout << "Default constructor Cat" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
  std::cout << "Copy constructor Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
  Animal::operator=(rhs);
  std::cout << "Copy assignement operator Cat" << std::endl;
  return *this;
}

Cat::~Cat()
{
  std::cout << "Destructor Cat" << std::endl;
}

void  Cat::makeSound() const
{
  std::cout << "Meow" << std::endl;
}
