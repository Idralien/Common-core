/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:42:07 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 18:57:16 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
  _brain = new Brain();
  type = "Cat";
  std::cout << "Default constructor Cat" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
  _brain = new Brain(*other._brain);
  std::cout << "Copy constructor Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
  if (this != &rhs)
  {
    AAnimal::operator=(rhs);
    delete _brain;
    _brain = new Brain(*rhs._brain);
  }
  std::cout << "Copy assignement operator Cat" << std::endl;
  return *this;
}

Cat::~Cat()
{
  delete _brain;
  std::cout << "Destructor Cat" << std::endl;
}

void  Cat::makeSound() const
{
  std::cout << "Meow" << std::endl;
}

void  Cat::learn(const std::string& idea)
{
  _brain->setIdea(0, idea);
}

void  Cat::think() const
{
  std::cout << "Cat thinks: " << _brain->getIdea(0) << std::endl;
}
