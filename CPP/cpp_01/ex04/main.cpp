/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:56:27 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 16:00:08 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplace.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Must be: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	if (!fileReplace::replaceInFile(filename, s1, s2))
		return 1;

	std::cout << "succes" << std::endl;
	return 0;
}
