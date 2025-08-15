/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:36:41 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 15:40:16 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>

class fileReplace
{
	public:
		static bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);
	private:
		static std::string replaceOccurences(const std::string& content, const std::string& s1, const std::string& s2);
};

#endif
