/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:09:20 by acaffard          #+#    #+#             */
/*   Updated: 2024/08/30 14:47:50 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    current_index = 0;
    contact_array[8];
    std::cout << "New PhoneBook Created" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook Destroyed" << std::endl;
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
    this->contact_array[this->current_index].setFirstName();
    this->contact_array[this->current_index].setLastName();
    this->contact_array[this->current_index].setNickName();
    this->contact_array[this->current_index].setPhoneNumber();
    this->contact_array[this->current_index].setSecret();
    this->current_index = (this->current_index + 1) % 8;
    std::cout << std::endl << "New Contact Created" << std::endl;
}

void PhoneBook::print()
{
    for(int i = 0; i < 8; i++)
    {
        std::cout.flags(std::ios::right);
        std::cout.width(10);
        std::cout << i + 1 << "|";
        std::cout.flags(std::ios::right);
        std::cout.width(10);
        if (this->contact_array[i].getFirstName().length() > 10)
            std::cout << this->contact_array[i].getFirstName().substr(0, 9) + ".";
        else 
            std::cout << this->contact_array[i].getFirstName();
        std::cout << "|";
        std::cout.width(10);
        if (this->contact_array[i].getLastName().length() > 10)
            std::cout << this->contact_array[i].getLastName().substr(0, 9) + ".";
        else 
            std::cout << this->contact_array[i].getLastName();
        std::cout << "|";
        std::cout.width(10);
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
    int value;
    std::string inputValue;
    do
    {
        
        print();
        std::cout << "Which contact do you want to see ? :";
        do
        {
            if (std::cin.eof())
            {
                std::cin.clear();
                clearerr(stdin);
                std::cout << std::endl;
            }
            std::getline(std::cin, inputValue);
            std::cout << std::endl;
        } while (inputValue.empty());
        value = std::stoi(inputValue);
    } while (!checkValue(value));
    contact_array[value - 1].print();
}
