/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:39:07 by brsantsc          #+#    #+#             */
/*   Updated: 2025/05/08 17:23:32 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& rhs);
    ~Cat();

    void  makeSound() const;
    void  learn(const std::string& idea);
    void  think() const;

  private:
    Brain* _brain;
};

#endif
