/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:39:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 13:03:06 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	*this = copy;
}

Cure::~Cure()
{}

Cure& Cure::operator=(const Cure &copy)
{
	this->_type = copy.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	return new(std::nothrow) Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}