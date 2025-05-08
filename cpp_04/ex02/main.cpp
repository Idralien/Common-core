/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:44:25 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 19:01:01 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "===== 1. Abstract Class Test =====" << std::endl;
    // Uncommenting this should fail to compile (good!):
    // AAnimal* abstract = new AAnimal(); 

    std::cout << "\n===== 2. Polymorphism Test =====" << std::endl;
    AAnimal* animals[4];
    for (int i = 0; i < 2; i++) {
        animals[i] = new Dog();
        animals[i]->makeSound();  // Should print "Bark"
    }
    for (int i = 2; i < 4; i++) {
        animals[i] = new Cat();
        animals[i]->makeSound();  // Should print "Meow"
    }

    std::cout << "\n===== 3. Deep Copy Test =====" << std::endl;
    Dog originalDog;
    originalDog.learn("I love bones");
    
    Dog copyDog(originalDog);  // Should trigger Dog copy constructor
    copyDog.learn("I prefer steaks");
    
    std::cout << "Original Dog's thought: ";
    originalDog.think();  // Should print "I love bones"
    
    std::cout << "Copy Dog's thought: ";
    copyDog.think();      // Should print "I prefer steaks"

    std::cout << "\n===== 4. Destruction Test =====" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete animals[i];  // Should call correct destructor chain
    }

    return 0;
}
