/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:32:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 17:21:42 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
  _brain = new Brain();
  type = "Dog";
  std::cout << "Default Dog constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
  _brain = new Brain(*other._brain);
  std::cout << "Copy constructor Dog" << std::endl;
}
Dog& Dog::operator=(const Dog& rhs)
{
  if (this != &rhs)
  {
    Animal::operator=(rhs);
    delete _brain;
    _brain = new Brain(*rhs._brain);
  }
  std::cout << "assignment operator Dog" << std::endl;
  return *this;
}

Dog::~Dog()
{
  delete _brain;
  std::cout << "Destructor Dog" << std::endl;
}

void  Dog::makeSound() const
{
  std::cout << "Bark" << std::endl;
}

void  Dog::learn(const std::string& idea)
{
  _brain->setIdea(0, idea);
}

void  Dog::think() const
{
  std::cout << "Dog thinks: " << _brain->getIdea(0) << std::endl;
}
