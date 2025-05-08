/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:30 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:42:18 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
  public:
    AAnimal& operator=(const AAnimal& rhs);
    virtual ~AAnimal();

    std::string getType() const;
    virtual void makeSound() const = 0;

  protected:
    std::string type;

    AAnimal();
    AAnimal(const AAnimal& other);
};

#endif
