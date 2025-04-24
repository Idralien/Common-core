/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:00:41 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/27 17:20:21 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain
{
  public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    Brain& operator=(const Brain& rhs);

    void  setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
  private:
    std::string ideas[100];
};

#endif
