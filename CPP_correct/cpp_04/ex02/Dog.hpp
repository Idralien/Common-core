/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:29:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:44:07 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
  public:
    Dog();
    Dog(const Dog& type);
    Dog& operator=(const Dog& rhs);
    ~Dog();

    void  makeSound() const;
    void  think() const;
    void  learn(const std::string& idea);
  private:
    Brain* brain;
};

#endif
