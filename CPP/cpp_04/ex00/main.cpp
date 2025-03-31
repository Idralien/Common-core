/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:01:30 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 15:02:10 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
  std::cout << "===== Correct Animals =====" << std::endl;
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // Will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << "\n===== Wrong Animals =====" << std::endl;
  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound(); // Will output WrongAnimal sound!
  wrongMeta->makeSound();

  delete wrongMeta;
  delete wrongCat;

  std::cout << "\n===== Additional Tests =====" << std::endl;
  Animal animal;
  Dog dog;
  Cat cat;

  Animal animalCopy(animal);
  Dog dogCopy(dog);
  Cat catCopy(cat);

  animal = animalCopy;
  dog = dogCopy;
  cat = catCopy;

  return 0;
}
