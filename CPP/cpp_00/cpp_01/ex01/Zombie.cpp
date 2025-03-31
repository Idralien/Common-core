/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:42:48 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/24 16:14:23 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("unnamed") {}

//constructor
Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << name << " has arrived!" << std::endl;
}

//destructor
Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been killed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << "Braaaaaiiiinnnzzzz..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
