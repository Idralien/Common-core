/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:10:29 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:46:31 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain())
{
  type = "Cat";
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
  std::cout << "Cat copy constructor called" << std::endl;
  brain = new Brain(*other.brain); // Deep copy
}

Cat& Cat::operator=(const Cat& rhs)
{
  std::cout << "Cat copy assignment called" << std::endl;
  if (this != &rhs)
  {
    AAnimal::operator=(rhs);
    delete brain;
    brain = new Brain(*rhs.brain); // Deep copy
  }
  return *this;
}

Cat::~Cat()
{
  std::cout << "Cat destructor called" << std::endl;
  delete brain;
}

void Cat::makeSound() const
{
  std::cout << "Meow meow!" << std::endl;
}

void Cat::think() const
{
  std::cout << "Cat is thinking: " << brain->getIdea(0) << std::endl;
}

void Cat::dream() const
{
  std::cout << "Cat is dreaming about: " << brain->getIdea(1) << std::endl;
}
