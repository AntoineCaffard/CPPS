/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:04:15 by acaffard          #+#    #+#             */
/*   Updated: 2025/05/06 10:22:47 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter *ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string value)
{
	if (is_zero(value))
		print_zero();
	else if (is_special(value))
		print_special(value);
	else if (is_char(value))
		convert_char(value);
	else if (is_int(value))
		convert_int(value);
	else if (is_float(value))
		convert_float(value);
	else if (is_double(value))
		convert_double(value);
	else
		print_special("nan");
}

void convert_char(std::string value)
{
	std::cout << "char: ";
	if (value[0] < 33 || value[0] > 126)
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << value << std::endl;
	std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
}

void convert_int(std::string value)
{
	double	result;
	
	result = strtod(value.c_str(), NULL);
	print_char(result);
	std::cout << "int: " << static_cast<int>(result) << std::endl;
	std::cout << "float: " << static_cast<int>(result) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(result) << ".0" << std::endl;
}

void convert_float(std::string value)
{
	double	result;
	
	result = strtod(value.c_str(), NULL);
	print_char(result);
	print_int(result);
	std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
	std::cout << "double: " << result << std::endl;
}

void convert_double(std::string value)
{
	double	result;
	
	result = strtod(value.c_str(), NULL);
	if (errno == ERANGE)
		(result < 0) ? print_special("-inf") : print_special("inf");
	else
	{
		print_char(result);
		print_int(result);
		print_float(result);
		std::cout << "double: " << result << std::endl;
	}
}