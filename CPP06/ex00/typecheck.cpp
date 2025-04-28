/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecheck.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:43:26 by acaffard          #+#    #+#             */
/*   Updated: 2025/04/28 16:51:10 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typecheck.hpp"
#include <cmath>

bool	is_zero(std::string value)
{
	return (value == "0" || value == "0.0f" || value == "0.0");
}

bool	is_char(std::string value)
{
	return (value.length() == 1);
}

bool	is_int(std::string value)
{
	double	result;
	char	*endPointer;

	if (value.find('.'))
		return false;
	result = strtod(value.c_str(), &endPointer);
	if (*endPointer)
		return false;
	if (result < std::numeric_limits<int>::lowest() || result > std::numeric_limits<int>::max())
		return false;
	return true;
}

bool	is_float(std::string value)
{
	double	result;
	char	*endPointer;
	result = strtod(value.c_str(), &endPointer);
	if (result < std::numeric_limits<float>::lowest() || result > std::numeric_limits<float>::max())
		return false;
	if (!*endPointer || (*endPointer == 'f' && !*(endPointer + 1)))
		return true;
	return false;
}

bool	is_double(std::string value)
{
	double	result;
	char	*endPointer;
	result = strtod(value.c_str(), &endPointer);
	if (*endPointer)
		return false;
	return true;
}

bool is_special(std::string value)
{
	if (value == "nan" || value == "nanf")
		return true;
	else if (value == "inf" || value == "inff" || value == "+inf" || value == "+inff")
		return true;
	else if (value == "-inf" || value == "-inff")
		return true;
	else
		return false;
}