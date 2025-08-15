/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:12:03 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 11:33:31 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap clap1("Iron Man");
  ClapTrap clap2("Dr. Doom");

  clap1.attack("Dr. Doom");
  clap2.takeDamage(5);
  clap2.beRepaired(3);
  
  clap2.attack("Iron Man");
  clap1.takeDamage(8);

  clap1.beRepaired(10);
  clap1.attack("Dr. Doom");

  clap2.takeDamage(20);
  clap2.beRepaired(5);
  clap2.attack("Dr. Doom");

  return 0;
}
