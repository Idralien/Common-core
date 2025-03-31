/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:40:27 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/25 16:07:04 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplace.hpp"

bool	fileReplace::replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: Filename and s1 can't be empty" << std::endl;
		return false;
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return false;
	}

	std::string content;
	std::string line;

	while (std::getline(inputFile, line))
		content += line + "\n";

	inputFile.close();

	std::string newContent = replaceOccurences(content, s1, s2);

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: can't create file " << outputFilename << std::endl;
		return false;
	}

	outputFile << newContent;
	outputFile.close();

	return true;
}

std::string fileReplace::replaceOccurences(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t			pos = 0;
	size_t			prevPos = 0;

	while ((pos = content.find(s1, prevPos)) != std::string::npos)
	{
		result.append(content, prevPos, pos - prevPos);
		result += s2;
		prevPos = pos + s1.length();
	}
	result.append(content, prevPos, content.length() - prevPos);

	return result;
}
