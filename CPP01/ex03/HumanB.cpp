/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:05:42 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/06 16:13:35 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}

void HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " attacks with his bare hands" << std::endl;
	else
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
}