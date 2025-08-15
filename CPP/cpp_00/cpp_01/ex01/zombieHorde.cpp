/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:28:44 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/24 15:29:01 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int	i = 0;
	Zombie* horde = new Zombie[N]; // Allocate N zombies in single allocation
	
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}
