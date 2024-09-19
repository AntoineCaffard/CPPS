/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:03:17 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/19 17:24:25 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "Utils.h"

Contact::Contact()
{
    firstName="";
    lastName="";
    nickName="";
    phoneNumber="";
    darkestSecret="";
}

Contact::~Contact()
{
}

std::string Contact::getFirstName()
{
    return (this->firstName);
}
std::string Contact::getLastName()
{
    return (this->lastName);
}

std::string Contact::getNickName()
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}

std::string Contact::getSecret()
{
    return (this->darkestSecret);
}

void Contact::setFirstName(std::string value)
{
    this->firstName = value;
}

void Contact::setLastName(std::string value)
{

    this->lastName = value;
}

void Contact::setNickName(std::string value)
{
    this->nickName = value;
}

void Contact::setPhoneNumber(std::string value)
{
    this->phoneNumber = value;
}

void Contact::setSecret(std::string value)
{
    this->darkestSecret = value;
}

void Contact::print()
{
    if (firstName.empty())
        std::cout << "\033[1;34mEmpty Contact\033[0m" << std::endl << std::endl;
    else
    {
        std::cout << "";
        std::cout << "\033[1;33mFirst Name : \033[1;34m" << this->firstName << std::endl;
        std::cout << "\033[1;33mLast Name : \033[1;34m" << this->lastName << std::endl;
        std::cout << "\033[1;33mNickname : \033[1;34m" << this->nickName << std::endl;
        std::cout << "\033[1;33mPhone Number : \033[1;34m" << this->phoneNumber << std::endl;
        std::cout << "\033[1;33mDarkest Secret \033[1;34m: " << this->darkestSecret << std::endl << std::endl;
        std::cout << "\033[0m";
    }
}
