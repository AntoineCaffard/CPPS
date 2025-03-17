/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:12:48 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/17 09:38:33 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "TypeDefiner.hpp"
#include "Printers.hpp"

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

static void	convert(std::string value)
{
	switch(defineType(value))
	{
		case CHAR :
			convertChar(value);
			break;
		case INT :
			convertInt(value);
			break;
		case FLOAT :
			convertFloat(value);
			break;
		case DOUBLE :
			convertDouble(value);
			break;
		case SPECIAL :
			printSpecial(value);
			break;
		default :
			break;
	};
}
