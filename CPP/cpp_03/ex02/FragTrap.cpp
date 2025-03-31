/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:30:49 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 12:33:37 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
  if (this != &rhs)
  {
    ClapTrap::operator=(rhs);
  }
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
  if (_hitPoints == 0 || _energyPoints == 0)
  {
    std::cout << "FragTrap " << _name << " can't attack - no hit points or energy left!" << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "FragTrap " << _name << " smashes " << target
    << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
  std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}
