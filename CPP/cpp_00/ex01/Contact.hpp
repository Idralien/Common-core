/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:27:38 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/19 16:42:47 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define	CONTACT_H

#include "terminal.hpp"

class	Contact
{
	public:
		Contact();
		void	setFirstName(const std::string& firstName);
		void	setLastName(const std::string& lastName);
		void	setNickname(const std::string&	nickname);
		void	setPhoneNumber(const std::string& phoneNumber);
		void	setDarkestSecret(const std::string& darkestSecret);

		std::string	getFirstName() const;
		std::string getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;



private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif
