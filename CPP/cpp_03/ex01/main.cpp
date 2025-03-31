/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:50:11 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 11:53:10 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
  // Test construction/destruction order
  std::cout << "\n=== Constructors ===" << std::endl;
  ScavTrap scav1("SCAV-man");
  
  std::cout << "\n=== Member functions ===" << std::endl;
  scav1.attack("Iron Man");
  scav1.guardGate();
  scav1.takeDamage(30);
  scav1.beRepaired(10);
  
  std::cout << "\n=== Copy tests ===" << std::endl;
  ScavTrap scav2(scav1);
  scav2 = scav1;
  
  std::cout << "\n=== Destruction ===" << std::endl;
  return 0;
}
