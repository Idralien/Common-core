/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:08:42 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 00:06:31 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class Weapon;

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack() const;

	private:
		std::string name;
		Weapon& weapon;
};

#endif
