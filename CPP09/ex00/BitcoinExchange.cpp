/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:10:13 by acaffard          #+#    #+#             */
/*   Updated: 2025/05/07 19:27:49 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	try
	{
		_initDatabase();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void) copy;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::_initDatabase()
{
	std::string line;
	std::ifstream file("data.csv");
	if (!file)
		throw FileOpenFailException();
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::size_t pos = line.find(",");
		_database[line.substr(0, pos)] = strtof(line.substr(pos + 1).c_str(), NULL);
	}
	file.close();
}

void BitcoinExchange::parseLine(const std::string &line)
{
	regex_t test;
	std::string type = "^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| (0|([0-9]{1,3}(\\.[0-9]+)?|1000))$";

	int i = regcomp(&test, type.c_str(), REG_EXTENDED);
	if (i)
		throw FileOpenFailException();
	i = regexec(&test, line.c_str(), 0, NULL, 0);
	regfree(&test);
	if (!i)
		return ;
}

void BitcoinExchange::_printDatabase()
{
	std::map<std::string, float>::iterator it=_database.begin();
	for (; it != _database.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}

void BitcoinExchange::convert(std::string date, float value)
{
	std::map<std::string, float>::reverse_iterator rit = _database.rbegin();
	for (; rit != _database.rend(); ++rit)
	{
		if (date >= rit->first)
		{
			std::cout << std::fixed << std::setprecision(2) << value * rit->second << std::endl;
			return ;
		}
	}
}