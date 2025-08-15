/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:57:18 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/21 15:45:44 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//constructor
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "zombie " << name << " has arrived!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "zombie " << name << " is destroyed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
