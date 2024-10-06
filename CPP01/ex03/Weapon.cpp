/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:11:45 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/06 16:01:56 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}