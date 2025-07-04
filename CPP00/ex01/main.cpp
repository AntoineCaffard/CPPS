/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:16:52 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/24 10:41:15 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"

int main(void)
{
    PhoneBook Book;
    std::string input_choice;
    std::system("clear");
    std::cout << "\033[1;31mWELCOME TO YOUR PHONEBOOK !\033[0m" << std::endl << std::endl;
    while (1)
    {
        std::cin.clear();
        clearerr(stdin);
        std::cout << "\033[1;34mADD\033[0m | \033[1;33mSEARCH\033[0m | \033[1;32mEXIT\033[0m" << std::endl << "Choose your option : ";
        std::getline(std::cin, input_choice);
        std::cout << std::endl;
        if (input_choice == "EXIT")
            break;
        if (input_choice == "ADD")
        {
            Book.addNewContact();
            continue;
        }
        if (input_choice == "SEARCH")
        {
			std::system("clear");
            Book.search();
            continue;
        }
        else
        {
            std::system("clear");
            std::cout << "\033[1;31mINVALID INPUT\033[0m" << std::endl << std::endl;
        }
    }
}