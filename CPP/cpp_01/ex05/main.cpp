/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:34:31 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 16:44:13 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl harl;

  std::cout << "=== DEBUG ===" << std::endl;
  harl.complain("DEBUG");

  std::cout << "\n=== INFO ===" << std::endl;
  harl.complain("INFO");

  std::cout << "\n=== WARNING ===" << std::endl;
  harl.complain("WARNING");

  std::cout << "\n=== ERROR ===" << std::endl;
  harl.complain("ERROR");

  std::cout << "\n=== KAREN MODE ===" << std::endl;
  harl.complain("KAREN MODE");
  return 0;
}
