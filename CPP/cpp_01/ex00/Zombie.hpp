/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:05:59 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/21 15:41:15 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	public:
					Zombie(std::string name); //constructor
					~Zombie(); //Destructor

					Zombie* newZombie(std::string name);
					void	randomChump(std::string name);
					void	announce(void);
	private:
					std::string name;
};

#endif
