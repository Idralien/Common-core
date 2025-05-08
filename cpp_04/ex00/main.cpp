/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:01:30 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 19:41:01 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void runBasicTests() {
    std::cout << "\n=== BASIC TESTS (REQUIRED) ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound
    
    delete meta;
    delete j;
    delete i;
}

void runWrongAnimalTests() {
    std::cout << "\n=== WRONG ANIMAL TESTS ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // WrongAnimal sound (not polymorphic)
    wrongMeta->makeSound(); // WrongAnimal sound
    
    // Direct WrongCat test
    WrongCat pureWrongCat;
    std::cout << pureWrongCat.getType() << " " << std::endl;
    pureWrongCat.makeSound(); // WrongCat sound
    
    delete wrongMeta;
    delete wrongCat;
}

void runCopyTests() {
    std::cout << "\n=== COPY TESTS ===" << std::endl;
    
    // Dog copy tests
    Dog originalDog;
    originalDog.makeSound();
    
    Dog copyConstructedDog(originalDog);
    copyConstructedDog.makeSound();
    
    Dog copyAssignedDog;
    copyAssignedDog = originalDog;
    copyAssignedDog.makeSound();
    
    // Cat copy tests
    Cat originalCat;
    originalCat.makeSound();
    
    Cat copyConstructedCat(originalCat);
    copyConstructedCat.makeSound();
    
    Cat copyAssignedCat;
    copyAssignedCat = originalCat;
    copyAssignedCat.makeSound();
}

void runArrayTests() {
    std::cout << "\n=== ARRAY TESTS ===" << std::endl;
    const Animal* animals[4];
    
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    for (int i = 0; i < 4; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }
}

void runPolymorphismEdgeCases() {
    std::cout << "\n=== POLYMORPHISM EDGE CASES ===" << std::endl;
    
    // Animal reference to Dog
    Dog dog;
    Animal& animalRef = dog;
    std::cout << animalRef.getType() << ": ";
    animalRef.makeSound(); // Should use Dog's implementation
    
    // Animal pointer to Cat
    Cat cat;
    Animal* animalPtr = &cat;
    std::cout << animalPtr->getType() << ": ";
    animalPtr->makeSound(); // Should use Cat's implementation
}

void runDestructionOrderTests() {
    std::cout << "\n=== DESTRUCTION ORDER TESTS ===" << std::endl;
    
    std::cout << "Creating Dog in block scope:" << std::endl;
    {
        Dog scopedDog;
    } // Should show Dog then Animal destructor
    
    std::cout << "\nCreating Cat in block scope:" << std::endl;
    {
        Cat scopedCat;
    } // Should show Cat then Animal destructor
}

int main() {
    runBasicTests();       // Keep the original required tests
    runWrongAnimalTests(); // Wrong animal demonstration
    runCopyTests();        // Verify copy constructors/assignment
    runArrayTests();       // Test array of animals
    runPolymorphismEdgeCases(); // Additional polymorphism cases
    runDestructionOrderTests(); // Verify destruction order
    
    return 0;
}
