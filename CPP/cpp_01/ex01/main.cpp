/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:08:21 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/24 15:12:15 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 5; //nbr of zombies in the horde
	int	i	= 0;
	std::string name = "HordeZombie";

	Zombie* horde = zombieHorde(N, name);

	while(i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;

	return 0;
}
