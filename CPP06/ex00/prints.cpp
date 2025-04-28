/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:47:28 by acaffard          #+#    #+#             */
/*   Updated: 2025/04/28 16:28:45 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prints.hpp"


void print_zero()
{
	std::cout << "char: Non Displayable" << std::endl;
	std::cout << "int: Non Displayable" << std::endl;
	std::cout << "float: 0.0f" << std::endl;
	std::cout << "double: 0.0" << std::endl;
}

void print_char(double value)
{
	std::cout << "char: ";
	if (value < 0 || value > 255)
		std::cout << "Impossible" << std::endl;
	else if (value < 33 || value > 126)
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << static_cast<char>(value) << std::endl;
}

void print_int(double value)
{
	std::cout << "int: ";
	if (value < std::numeric_limits<int>::lowest() || value > std::numeric_limits<int>::max())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void print_float(double value)
{
	std::cout << "float: ";
	if (value < std::numeric_limits<float>::lowest())
		std::cout << "-inff" << std::endl;
	else if (value > std::numeric_limits<float>::max())
		std::cout << "+inff" << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;
}

void print_special(std::string value)
{
	if (value == "nan" || value == "nanf")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (value == "inf" || value == "inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (value == "-inf" || value == "-inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}