/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:12:48 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/20 08:18:42 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return *this;
}

// static void	convert(std::string value)
// {}
