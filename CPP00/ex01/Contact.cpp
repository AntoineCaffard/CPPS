/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:03:17 by acaffard          #+#    #+#             */
/*   Updated: 2024/08/29 16:30:47 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "Utils.h"

Contact::Contact()
{
    firstName = inputString(("first name"));
    lastName = inputString(("last name"));
    nickName = inputString(("nickname"));
    phoneNumber = inputValidPhoneNumber();
    darkestSecret = inputString(("darkest secret"));
    std::cout << "Contact " << nickName << " Created." << std::endl;
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

void Contact::setNickName(std::string newNickName)
{
    this->nickName = newNickName;
}

void Contact::setPhoneNumber(std::string newPhoneNumber)
{
    this->phoneNumber = newPhoneNumber;
}

void Contact::print()
{
    std::cout << this->firstName << std::endl;
    std::cout << this->lastName << std::endl;
    std::cout << this->nickName << std::endl;
    std::cout << this->phoneNumber << std::endl;
    std::cout << this->darkestSecret << std::endl;
}
