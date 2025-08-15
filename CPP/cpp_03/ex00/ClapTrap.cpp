/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:02:29 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 11:11:54 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("Default"),
	_hitPoints(10),
  _energyPoints(10),
  _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
  _name(name),
  _hitPoints(10),
  _energyPoints(10),
  _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
  *this = other;
  std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
  if (this != &rhs)
	{
  	this->_name = rhs._name;
  	this->_hitPoints = rhs._hitPoints;
  	this->_energyPoints = rhs._energyPoints;
  	this->_attackDamage = rhs._attackDamage;
  }
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
  if (_hitPoints == 0 || _energyPoints == 0)
	{
  	std::cout << "ClapTrap " << _name << " can't attack - no hit points or energy left!" << std::endl;
  	return;
  }
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (_hitPoints == 0)
	{
  	std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
  	return;
  }
  if (amount >= _hitPoints)
	{
  	_hitPoints = 0;
  	std::cout << "ClapTrap " << _name << " takes " << amount
			<< " damage and is destroyed!" << std::endl;
  } 
	else
	{
  	_hitPoints -= amount;
  	std::cout << "ClapTrap " << _name << " takes " << amount
			<< " damage! (" << _hitPoints << " HP remaining)" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (_hitPoints == 0 || _energyPoints == 0)
	{
  	std::cout << "ClapTrap " << _name << " can't repair - no hit points or energy left!" << std::endl;
  	return;
  }
  _energyPoints--;
  _hitPoints += amount;
  std::cout << "ClapTrap " << _name << " repairs itself for " << amount
		<< " hit points! (" << _hitPoints << " HP now)" << std::endl;
}
