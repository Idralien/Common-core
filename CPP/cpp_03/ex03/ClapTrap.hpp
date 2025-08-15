/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:41:48 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 11:47:05 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:  // Changed from private to protected for inheritance
  	std::string     _name;
  	unsigned int    _hitPoints;
  	unsigned int    _energyPoints;
  	unsigned int    _attackDamage;

	public:
  	ClapTrap();
  	ClapTrap(std::string name);
  	ClapTrap(const ClapTrap& other);
  	ClapTrap& operator=(const ClapTrap& rhs);
  	~ClapTrap();

  	void attack(const std::string& target);
  	void takeDamage(unsigned int amount);
  	void beRepaired(unsigned int amount);
};

#endif
