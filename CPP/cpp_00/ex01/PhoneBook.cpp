/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:18:57 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/19 17:13:08 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void	PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);

	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		contacts[oldestContactIndex] = newContact;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
}

void	PhoneBook::searchContact() const
{
	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	displayContactList();

	int	index;
	std::cout << "Enter index: ";
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (index >= 0 && index < contactCount)
	{
		displayContactDetails(index);
	}
	else
	{
		std::cout << "Invalid index!" << std::endl;
	}
}

void	PhoneBook::displayContactList() const
{
	int	i = 0;
	while (i < contactCount)
	{
		std::cout << std::setw(10) << i << "|"
							<< std::setw(10) << truncateField(contacts[i].getFirstName()) << "|"
							<< std::setw(10) << truncateField(contacts[i].getLastName()) << "|"
							<< std::setw(10) << truncateField(contacts[i].getNickname()) << std::endl;
		i++;
	}
}

void	PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateField(const std::string& field) const
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}
