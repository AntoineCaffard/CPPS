/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDefiner.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:30:27 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/20 09:52:35 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeDefiner.hpp"

bool isInt(std::string &value)
{
	try
	{
		char *pos;
		strtol(value.c_str(), &pos, 10);
		return *pos == '\0';
	}
	catch(...)
	{
		return false;
	}
}

bool isFloat(std::string &value)
{
	try
	{
		char *pos;
		std::strtof(value.c_str(), &pos);
		return (*pos == 'f' && !*(pos + 1));
	}
	catch(...)
	{
		return false;
	}
}

bool isDouble(std::string &value)
{
	try
	{
		char *pos;
		std::strtod(value.c_str(), &pos);
		return *pos == '\0';
	}
	catch(...)
	{
		return false;
	}
}

bool isChar(std::string &value)
{
	if (value.length() == 1)
		return true;
	return false;

}

bool isSpecial(std::string &value)
{
	if (value == "nan" || value == "nanf" || value == "+inff" || value == "-inff" || value == "+inf" || value == "-inf")
		return true;
	return false;
}

int	defineType(std::string &value)
{
	if (isSpecial(value))
		return SPECIAL;
	if (isChar(value))
		return CHAR;
	if (isInt(value))
		return INT;
	if (isFloat(value))
		return FLOAT;
	if (isDouble(value))
		return DOUBLE;
	return IMPOSSIBLE;
}
