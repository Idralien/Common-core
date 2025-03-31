/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:44:25 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:45:13 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  // This would now cause a compilation error:
  // AAnimal* animal = new AAnimal(); 
  
  // Proper usage with derived classes:
  AAnimal* animals[4];
  
  for (int i = 0; i < 2; i++)
  {
    animals[i] = new Dog();
  }
  
  for (int i = 2; i < 4; i++)
  {
    animals[i] = new Cat();
  }

  for (int i = 0; i < 4; i++)
  {
    animals[i]->makeSound();
    delete animals[i];
  }

  return 0;
}
