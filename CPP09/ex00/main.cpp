/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:57:40 by acaffard          #+#    #+#             */
/*   Updated: 2025/05/07 18:49:39 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::string line;
	std::ifstream file;

	try
	{
		if (ac != 2 || !av[1])
			throw ArgumentException();
		BitcoinExchange exchanger;
		
		std::ifstream file(av[1]);
		if (!file)
			throw FileOpenFailException();
		std::getline(file, line);
		while (std::getline(file, line))
			exchanger.processLine(line);
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}