/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:29:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 17:16:48 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  public:
    Dog();
    Dog(const Dog& type);
    Dog& operator=(const Dog& rhs);
    ~Dog();

    void  makeSound() const;
    void  learn(const std::string& rhs);
    void  think() const;

  private:
    Brain* _brain;
};

#endif
