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

void	BitcoinExchange::_checkLineFormat(const std::string &line)
{
	regex_t test;
	std::string type = "^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| (0|([0-9]{1,3}(\\.[0-9]+)?|1000))$";

	int errorcode = regcomp(&test, type.c_str(), REG_EXTENDED);
	if (errorcode)
		throw RegexCreationFailException();
	errorcode = regexec(&test, line.c_str(), 0, NULL, 0);
	regfree(&test);
	if (!errorcode)
		return ;
	throw InvalidExpressionException();
}

void BitcoinExchange::_checkDate(const std::string &date)
{
	std::tm inputDate;
	std::memset(&inputDate, 0, sizeof(tm));
	inputDate.tm_year = strtod(date.c_str(), NULL) - 1900;
	inputDate.tm_mon = strtod((&date[5]), NULL) - 1;
	inputDate.tm_mday = strtod((&date[8]), NULL);
	std::tm realDate = inputDate;
	std::mktime(&inputDate);
	if (inputDate.tm_year != realDate.tm_year ||inputDate.tm_mon != realDate.tm_mon || inputDate.tm_mday != realDate.tm_mday  )
		throw InvalidDateException();
}

void BitcoinExchange::processLine(const std::string &line)
{
	try
	{
		this->_checkLineFormat(line);
		this->_checkDate(line.substr(0, line.find(" | ")));
		this->_convert(line.substr(0, line.find(" | ")), line.substr(line.find(" | ") + 3));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void BitcoinExchange::_printDatabase()
{
	std::map<std::string, float>::iterator it=_database.begin();
	for (; it != _database.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}

void BitcoinExchange::_convert(std::string date, std::string value)
{
	std::map<std::string, float>::reverse_iterator rit = _database.rbegin();
	for (; rit != _database.rend(); ++rit)
	{
		if (date >= rit->first)
		{
			std::cout << std::fixed << std::setprecision(2);
			std::cout << date << " => " << value << " = " << strtod(value.c_str(), NULL) * rit->second << std::endl;
			return ;
		}
	}
}