/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:05:05 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:23:22 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
  std::cout << "Brain default constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
  {
    std::ostringstream oss;
    oss << "Default idea " << i;
    ideas[i] = oss.str();
  }
}

Brain::Brain(const Brain& other)
{
  std::cout << "Brain copy constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
  {
    ideas[i] = other.ideas[i];
  }
}

Brain& Brain::operator=(const Brain& rhs)
{
  std::cout << "Brain copy assignment called" << std::endl;
  if (this != &rhs)
  {
    for (int i = 0; i < 100; i++)
    {
      ideas[i] = rhs.ideas[i];
    }
  }
  return *this;
}

Brain::~Brain()
{
  std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
  if (index >= 0 && index < 100)
  {
    ideas[index] = idea;
  }
}

std::string Brain::getIdea(int index) const
{
  if (index >= 0 && index < 100)
  {
    return ideas[index];
  }
  return "";
}
