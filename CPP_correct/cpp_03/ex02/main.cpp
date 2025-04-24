/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:29:16 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 12:29:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
  std::cout << "\n=== Constructors ===" << std::endl;
  FragTrap frag1("FR4G-TP");
  FragTrap frag2;

  std::cout << "\n=== Member functions ===" << std::endl;
  frag1.attack("Target Dummy");
  frag1.highFivesGuys();
  frag1.takeDamage(50);
  frag1.beRepaired(20);

  std::cout << "\n=== Copy tests ===" << std::endl;
  FragTrap frag3(frag1);
  frag2 = frag1;

  std::cout << "\n=== Destruction ===" << std::endl;
  return 0;
}
