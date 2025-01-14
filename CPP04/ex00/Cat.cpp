/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:27:09 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 12:27:09 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat : Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat : Copy Constructor Called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat : Destructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	(void) copy;
	return(*this);
}

void	Cat::makeSound() const
{
	std::cout << "Puuurrreow Meow" << std::endl;
}

std::ostream& operator<<(std::ostream &o, Cat const &cat)
{
	std::cout << std::endl << "----------------" << std::endl;
	std::cout << "-----Cat-----" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "type = " << cat.getType() << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	return o;
}
