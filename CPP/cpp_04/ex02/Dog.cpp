/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:08:50 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:46:50 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), brain(new Brain())
{
  type = "Dog";
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
  std::cout << "Dog copy constructor called" << std::endl;
  brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& rhs)
{
  std::cout << "Dog copy assignment called" << std::endl;
  if (this != &rhs)
  {
    AAnimal::operator=(rhs);
    delete brain;
     brain = new Brain(*rhs.brain); // Deep copy
  }
  return *this;
}

Dog::~Dog()
{
  std::cout << "Dog destructor called" << std::endl;
  delete brain;
}

void Dog::makeSound() const
{
  std::cout << "Woof woof!" << std::endl;
}

void Dog::think() const
{
  std::cout << "Dog is thinking: " << brain->getIdea(0) << std::endl;
}

void Dog::learn(const std::string& idea)
{
  brain->setIdea(0, idea);
}
