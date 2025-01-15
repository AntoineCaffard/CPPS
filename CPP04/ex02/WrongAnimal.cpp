/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:11:52 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/15 08:56:11 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Basic WrongAnimal")
{
	std::cout << "\e[1;32mWrongAnimal : Default Constructor Called\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << "\e[1;32mWrongAnimal : Attribute Constructor Called\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "\e[1;32mWrongAnimal : Copy Constructor Called\e[0m" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[1;31mAnimal : Destructor Called\e[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	_type = copy.getType();
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "blblblblblblblblblblblblblbl i'm atarded" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (this->_type);
}

