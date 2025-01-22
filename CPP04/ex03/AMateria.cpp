/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:24:38 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 13:01:44 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type)
{}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	this->_type = copy._type;
	return *this;
}

AMateria::~AMateria()
{}

std::string const	&AMateria::getType() const
{
	return _type;	
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Nothing happens to " << target.getName() << std::endl;
}
