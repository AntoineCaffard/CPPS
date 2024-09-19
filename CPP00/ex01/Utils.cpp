/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:24:20 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/19 11:03:51 by acaffard         ###   ########.fr       */
/*                 std::cout << "\033[2J\033[1;1H";                                                           */
/* ************************************************************************** */

#include "Utils.h"

bool checkPhoneNumberValidity(std::string phoneNumber)
{
    if (phoneNumber.empty() || phoneNumber.length() != 10)
    {
		std::system("clear");
        std::cerr << "\033[1;31mError : Bad Number Length\033[0m" << std::endl << std::endl;
        return (false);
    }
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
        {
			std::system("clear");
            std::cerr << "\033[1;31mError : Number must be only composed of digits\033[0m" << std::endl << std::endl;
            return (false);
        }
    }
    return (true);
}

int	skipSpaces(std::string str)
{
	int	i = 0;

	while (str[i] && (str[i] == ' ' || str[i] < 13))
		i++;
	return (i);
}

bool	checkValueEmpty(std::string str)
{
	if (!str.empty())
		return (false);
	std::system("clear");
    std::cerr << "\033[1;31mError : String is empty or composed of whitespaces\033[0m" << std::endl << std::endl;
	return (true);
}

std::string inputString(std::string type)
{
    std::string value;
    do
    {
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
        std::cout << "\033[1;33mPlease insert the contact's " << type << " :" << std::endl << "-->\033[0m";
        std::getline(std::cin, value);
		value = value.substr(skipSpaces(value));
    } while (checkValueEmpty(value));
    return (value);
}

std::string inputValidPhoneNumber()
{
    std::string phoneNumber;
    do
    {
        std::cout << "\033[1;33mPlease insert the contact's phone number :" << std::endl << "-->\033[0m";
        std::getline(std::cin, phoneNumber);
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
    } while (!checkPhoneNumberValidity(phoneNumber));
    return (phoneNumber);
}

bool checkValue(std::string value)
{
    if (value.length() != 1)
    {
		std::system("clear");
        std::cerr << "\033[1;31mError : Invalid id\033[0m" << std::endl << std::endl;
        return (false);
    }
    if (value[0] < '1' || value[0] > '8')
    {
		std::system("clear");
        std::cerr << "\033[1;31mError : Invalid id\033[0m" << std::endl << std::endl;
        return (false);
    }
    return (true);
}
