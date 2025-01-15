/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:06:38 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/08 08:18:57 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap : Default constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " : Name constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "ScavTrap : Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " : Destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &copy)
{
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energypoints = copy._energypoints;
	this->_attackdamage = copy._attackdamage;
	return *this;
}

void ScavTrap::guardGate()
{
	if (!_hitpoints)
	{
		std::cout << "ScavTrap " << _name << " is completely broken and cannot get in gate keeper mode" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!_hitpoints)
	{
		std::cout << "ScavTrap " << _name << " is completely broken and cannot attack " << target << std::endl;
		return ;
	}
	if (!_energypoints)
	{
		std::cout << "ScavTrap " << _name << " does not have enough energy to attack " << target << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackdamage << " points of damage" << std::endl;
	_energypoints--;
}

std::ostream& operator<<(std::ostream &o, ScavTrap &scavtrap)
{
	o << std::endl << "------------------" << std::endl;
	o << "-----SCAVTRAP-----" << std::endl;
	o << "------------------" << std::endl;
	o << "name : " << scavtrap.getName() << std::endl;
	o << "hitpoints : " << scavtrap.getHitPoints() << std::endl;
	o << "energypoints : " << scavtrap.getEnergyPoints() << std::endl;
	o << "------------------" << std::endl;
	return (o);
}