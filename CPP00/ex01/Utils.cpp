/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:24:20 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/02 14:33:44 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

bool checkPhoneNumberValidity(std::string phoneNumber)
{
    if (phoneNumber.empty() || phoneNumber.length() != 10)
    {
        std::cerr << "Error : Bad Number Length" << std::endl << std::endl;
        return (false);
    }
    for (int i = 0; i < phoneNumber.length(); i++)
    {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
        {
            std::cerr << "Error : Number must be only composed of digits" << std::endl << std::endl;
            return (false);
        }
    }
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
        std::cout << "Please insert the contact's " << type << " :" << std::endl << "-->"; 
        std::getline(std::cin, value);
    } while (value.empty());
    return (value);
}

std::string inputValidPhoneNumber()
{
    std::string phoneNumber;
    do
    {
        std::cout << "Please insert the contact's phone number :" << std::endl << "-->"; 
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
        std::cerr << "Error : Invalid id" << std::endl;
        return (false);
    }
    if (value[0] < '1' || value[0] > '8')
    {
        std::cerr << "Error : Invalid id" << std::endl;
        return (false);
    }
    return (true);
}