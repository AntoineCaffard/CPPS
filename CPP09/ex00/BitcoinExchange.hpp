/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:58:31 by acaffard          #+#    #+#             */
/*   Updated: 2025/06/12 16:20:15 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <regex.h>
#include <map>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"


class BitcoinExchange
{
	public :
		BitcoinExchange();
		virtual ~BitcoinExchange();
		
		void processLine(const std::string &line);

	private : 
		std::map<std::string, float> _database;
		
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void _initDatabase();
		void _printDatabase();
		void _checkLineFormat(const std::string &line);
		void _checkDate(const std::string &date);
		void _checkValue(const std::string &value);
		void _convert(std::string date, std::string value);

		class RegexCreationFailException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Error : Regex failed to be created");
			};
		};

		class InvalidExpressionException : public std::exception
		{	
			virtual const char *what() const throw()
			{
				std::cerr << RED;
				return ("Line Format is invalid");
			};
		};

		class InvalidDateException : public std::exception
		{
				virtual const char *what() const throw()
				{
					return ("Date is invalid");
				};
		};

		class InvalidValueException : public std::exception
		{
				virtual const char *what() const throw()
				{
					return ("Value is invalid");
				};
		};

		class NotInDatabaseException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Date is too old for the Database");
			};
		};
};

class ArgumentException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Error : You need to give one argument");
	};
};

class FileOpenFailException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Error : File failed to be opened");
	};
};