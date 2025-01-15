/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:05:40 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 12:05:40 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Basic Animal")
{
	std::cout << "\e[1;32mAAnimal : Default Constructor Called\e[0m" << std::endl;
}

AAnimal::AAnimal(const std::string &type): _type(type) 
{
	std::cout << "\e[1;32mAAnimal : Attribute Constructor Called\e[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "\e[1;32mAAnimal : Copy Constructor Called\e[0m" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "\e[1;31mAAnimal : Destructor Called\e[0m" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &copy)
{
	this->_type = copy.getType();
	return(*this);
}

const std::string&	AAnimal::getType() const
{
	return (this->_type);
}

