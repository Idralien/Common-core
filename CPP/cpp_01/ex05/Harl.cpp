/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:32:53 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 16:41:34 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const Harl::complaintLvl Harl::levels[4] = {
  {"DEBUG", &Harl::debug},
  {"INFO", &Harl::info},
  {"WARNING", &Harl::warning},
  {"ERROR", &Harl::error}
};

const std::string Harl::defaultMessage = "[ Probably complaining about insignificant problems ]";

void Harl::debug(void) {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do" << std::endl;
}

void Harl::info(void) {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
  for (int i = 0; i < 4; i++)
	{
  	if (level == levels[i].level)
		{
  		(this->*levels[i].function)();
  			return;
  	}
	}
  std::cout << defaultMessage << std::endl;
}
