/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:12:25 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 12:23:33 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	*this = copy;
}

Ice::~Ice()
{}

Ice& Ice::operator=(const Ice &copy)
{
	this->_type = copy.getType();
	return *this;
}

AMateria* Ice::clone() const
{
	return new(std::nothrow) Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}