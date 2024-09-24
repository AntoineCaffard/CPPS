/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:09:20 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/24 10:44:50 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    current_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::printContact(int id)
{
    if (id < 0 || id > 7)
        std::cerr << "Invalid ID" << std::endl;
    else
        this->contact_array[id].print();
}

void PhoneBook::addNewContact()
{
	std::system("clear");
    this->contact_array[this->current_index].setFirstName(inputString("first name"));
	std::system("clear");
    this->contact_array[this->current_index].setLastName(inputString("last name"));
	std::system("clear");
    this->contact_array[this->current_index].setNickName(inputString("nickname"));
	std::system("clear");
    this->contact_array[this->current_index].setPhoneNumber(inputValidPhoneNumber());
	std::system("clear");
    this->contact_array[this->current_index].setSecret(inputString("darkest secret"));
    this->current_index = (this->current_index + 1) % 8;
	std::system("clear");
}

void PhoneBook::print()
{
    std::cout << "\033[1;34mContact List :\033[0m" << std::endl << std::endl;
    for(int i = 0; i < 8; i++)
    {
        std::cout.flags(std::ios::right);
        std::cout << std::setw(10);
        std::cout << i + 1 << "|";
        std::cout.flags(std::ios::right);
        std::cout << std::setw(10);
        if (this->contact_array[i].getFirstName().length() > 10)
            std::cout << this->contact_array[i].getFirstName().substr(0, 9) + ".";
        else 
            std::cout << this->contact_array[i].getFirstName();
        std::cout << "|";
        std::cout << std::setw(10);
        if (this->contact_array[i].getLastName().length() > 10)
            std::cout << this->contact_array[i].getLastName().substr(0, 9) + ".";
        else 
            std::cout << this->contact_array[i].getLastName();
        std::cout << "|";
        std::cout << std::setw(10);
        if (this->contact_array[i].getNickName().length() > 10)
            std::cout << this->contact_array[i].getNickName().substr(0, 9) + ".";
        else 
            std::cout << this->contact_array[i].getNickName();
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}   

void PhoneBook::search()
{
    std::string value;
    do
    {
        print();
        std::cout << "\033[1;33mWhich contact do you want to see ? :\033[0m";
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
        std::getline(std::cin, value);
    } while (!checkValue(value));
    std::system("clear");
	this->printContact(value[0] - '0' - 1);
}

void PhoneBook::fill()
{
    for (int i = 0; i < 8; i++)
    {
        this->contact_array[i].setFirstName("AutoFilled");
        this->contact_array[i].setLastName("AutoFilled");
        this->contact_array[i].setNickName("AutoFilled");
        this->contact_array[i].setPhoneNumber("4242424242");
        this->contact_array[i].setSecret("AutoFilled");
    }
}
