/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:30 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 16:57:01 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
  public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& rhs);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0;

  protected:
    std::string type;
};

#endif
