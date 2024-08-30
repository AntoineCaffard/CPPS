/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:16:52 by acaffard          #+#    #+#             */
/*   Updated: 2024/08/30 14:43:14 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"

int main(void)
{
    PhoneBook Book;
    std::string input_choice;
    while (1)
    {
        std::cin.clear();
        if (std::cin.eof());
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << std::endl;
        }
        std::cout << "ADD | SEARCH | EXIT" << std::endl << "Choose your option : ";
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
            Book.search();
            continue;
        }
        else
            std::cout << "INVALID INPUT" << std::endl;
    }
}