/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecheck.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:43:26 by acaffard          #+#    #+#             */
/*   Updated: 2025/04/15 08:58:35 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typecheck.hpp"

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
	if ((*endPointer == 'f' && !(endPointer + 1)))
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
	if (result < std::numeric_limits<int>::lowest() || result > std::numeric_limits<int>::max())
		return false;
	return true;
}