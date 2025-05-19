/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:58:31 by acaffard          #+#    #+#             */
/*   Updated: 2025/05/07 18:49:08 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <regex.h>
#include <map>

class BitcoinExchange
{
	public :
		BitcoinExchange();
		virtual ~BitcoinExchange();
		
		void convert(std::string date, float value);
		void parseLine(const std::string &line);

	private : 
		std::map<std::string, float> _database;
		
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void _initDatabase();
		void _printDatabase();

		class FileOpenFailException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Error : File failed to be opened");
			};
		};
};