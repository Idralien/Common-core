/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:54:03 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 16:56:18 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  // Test basic functionality
  std::cout << "===== Basic Tests =====" << std::endl;
  Animal* animals[4];
  
  for (int i = 0; i < 2; i++)
  {
    animals[i] = new Dog();
    dynamic_cast<Dog*>(animals[i])->learn("I love bones!");
  }
  
  for (int i = 2; i < 4; i++)
  {
    animals[i] = new Cat();
    dynamic_cast<Cat*>(animals[i])->think();
  }

  // Test deep copying
  std::cout << "\n===== Copy Tests =====" << std::endl;
  Dog originalDog;
  originalDog.learn("Original idea");
  
  Dog copiedDog(originalDog);
  copiedDog.learn("Copied idea");
  
  originalDog.think();
  copiedDog.think();

  // Cleanup
  std::cout << "\n===== Cleanup =====" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    delete animals[i];
  }

  return 0;
}
