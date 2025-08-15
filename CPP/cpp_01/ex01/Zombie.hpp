/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:29:02 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/24 16:06:39 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name); //constructor

		~Zombie(); //destructor

		void	announce(void);
		void	setName(std::string name);


	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
