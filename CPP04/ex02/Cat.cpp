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

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "\e[1;32mCat : Default Constructor Called\e[0m" << std::endl;
	_brain = new(std::nothrow) Brain;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "\e[1;32mCat : Copy Constructor Called\e[0m" << std::endl;
	_brain = new(std::nothrow) Brain(*copy._brain);
}

Cat::~Cat()
{
	if (_brain)
		delete _brain;
	std::cout << "\e[1;31mCat : Destructor Called\e[0m" << std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		if (this->_brain)
			delete _brain;
		_brain = (copy._brain) ? new(std::nothrow) Brain(*copy._brain) : copy._brain;
	}
	return(*this);
}

void	Cat::makeSound() const
{
	std::cout << "Puuurrreow Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
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
