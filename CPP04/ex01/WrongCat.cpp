/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:26:38 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/15 08:59:14 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "\e[1;32mWrongCat : Default Constructor Called\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "\e[1;32mWrongCat : Copy Constructor Called\e[0m" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[1;31mWrongCat : Destructor Called\e[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	this->_type = copy.getType();
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}

