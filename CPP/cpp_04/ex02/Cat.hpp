/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:39:07 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:44:17 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
  public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& rhs);
    ~Cat();

    void  makeSound() const;
    void  think() const;
    void  dream() const;
  private:
    Brain* brain;
};

#endif
