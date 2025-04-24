/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:26:58 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 12:28:35 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
  	FragTrap();
  	FragTrap(std::string name);
  	FragTrap(const FragTrap& other);
  	FragTrap& operator=(const FragTrap& rhs);
  	~FragTrap();

  	void attack(const std::string& target);  // Override attack
  	void highFivesGuys();  // New special ability
};

#endif
