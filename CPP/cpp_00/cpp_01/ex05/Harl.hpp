/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:27:21 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 16:32:47 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public:
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		typedef	void	(Harl::*complaintFunction)(void);
		struct complaintLvl
		{
			std::string level;
			complaintFunction function;
		};
		static const complaintLvl levels[4];
		static const std::string defaultMessage;
};

#endif
