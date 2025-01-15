/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:05:40 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 12:05:40 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Basic Animal")
{
	std::cout << "\e[1;32mAnimal : Default Constructor Called\e[0m" << std::endl;
}

Animal::Animal(const std::string &type): _type(type) 
{
	std::cout << "\e[1;32mAnimal : Attribute Constructor Called\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "\e[1;32mAnimal : Copy Constructor Called\e[0m" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "\e[1;31mAnimal : Destructor Called\e[0m" << std::endl;
}

Animal& Animal::operator=(const Animal &copy)
{
	this->_type = copy.getType();
	return(*this);
}

const std::string&	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "............................." << std::endl;
}

std::ostream& operator<<(std::ostream &o, Animal const &animal)
{
	std::cout << std::endl << "----------------" << std::endl;
	std::cout << "-----Animal-----" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "type = " << animal.getType() << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	return o;
}
