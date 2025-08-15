/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:07:00 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 00:07:16 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack() const;

	private:
		std::string name;
		Weapon* weapon;
};

#endif
