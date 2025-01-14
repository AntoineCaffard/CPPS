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
	std::cout << "Animal : Default Constructor Called" << std::endl;
}

Animal::Animal(const std::string &type): _type(type)
{
	std::cout << "Animal : Attribute Constructor Called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal : Copy Constructor Called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal : Destructor Called" << std::endl;
}

Animal& Animal::operator=(const Animal &copy)
{
	this->_type = copy.getType();
	return(*this);
}

std::string	Animal::getType() const
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
