/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:54:03 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 17:27:46 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Test array of animals
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    std::cout << "\n===== Creating Animals =====" << std::endl;
    for (int i = 0; i < numAnimals/2; i++) {
        animals[i] = new Dog();
        dynamic_cast<Dog*>(animals[i])->learn("I'm a good dog");
    }
    for (int i = numAnimals/2; i < numAnimals; i++) {
        animals[i] = new Cat();
        dynamic_cast<Cat*>(animals[i])->learn("I'm a sneaky cat");
    }

    // Test deep copy
    std::cout << "\n===== Testing Deep Copy =====" << std::endl;
    Dog originalDog;
    originalDog.learn("Original dog's thought");
    
    Dog copyDog(originalDog);
    copyDog.learn("Copy dog's new thought");
    
    std::cout << "Original dog thinks: ";
    originalDog.think(); // Should show original thought
    
    std::cout << "Copy dog thinks: ";
    copyDog.think(); // Should show new thought

    // Cleanup
    std::cout << "\n===== Deleting Animals =====" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i]; // Should call correct destructors
    }

    return 0;
}
