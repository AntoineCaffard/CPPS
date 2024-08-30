/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:03:17 by acaffard          #+#    #+#             */
/*   Updated: 2024/08/30 14:48:30 by acaffard         ###   ########.fr       */
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
    std::cout << "Contact " << this->nickName << " Deleted." << std::endl;
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

void Contact::setFirstName()
{
    this->firstName = inputString(("first name"));
}

void Contact::setLastName()
{
    this->lastName = inputString(("last name"));
}

void Contact::setNickName()
{
    this->nickName = inputString(("nickname"));
}

void Contact::setPhoneNumber()
{
    this->phoneNumber = inputValidPhoneNumber();
}

void Contact::setSecret()
{
    this->darkestSecret = inputString(("darkest secret"));
}

void Contact::print()
{
    if (firstName.empty())
        std::cout << "Empty Contact" << std::endl;
    else
    {
        std::cout << this->firstName << std::endl;
        std::cout << this->lastName << std::endl;
        std::cout << this->nickName << std::endl;
        std::cout << this->phoneNumber << std::endl;
        std::cout << this->darkestSecret << std::endl << std::endl;
    }
}
