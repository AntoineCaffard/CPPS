/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:07:56 by acaffard          #+#    #+#             */
/*   Updated: 2024/11/25 10:20:33 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "New ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "New ScavTrap named " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " deleted" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in GateKeeper mode" << std::endl;
}