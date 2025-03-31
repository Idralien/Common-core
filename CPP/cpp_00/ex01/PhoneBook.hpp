/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:38:47 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/19 16:43:20 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "terminal.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		void	addContact();
		void	searchContact() const;

	private:
		Contact	contacts[8];
		int	contactCount;
		int	oldestContactIndex;

		void	displayContactList() const;
		void	displayContactDetails(int index) const;
		std::string	truncateField(const std::string& field) const;
};
#endif
