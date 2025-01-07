/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:06:38 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/07 12:23:44 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
}

ScavTrap::~ScavTrap()
{
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
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitpoints)
	{
		std::cout << "ScavTrap " << _name << " is completely broken and cannot repair itself "<< std::endl;
		return ;
	}
	if (!_energypoints)
	{
		std::cout << "ScavTrap " << _name << " does not have enough energy to repair itself" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " repairs itself of " << amount << " hitpoints" << std::endl;
	_energypoints--;
	_hitpoints = (_hitpoints + amount > 100) ? 100 : _hitpoints + amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_hitpoints)
	{
		std::cout << "ScavTrap " << _name << " is completely brokem and cannot attack " << target << std::endl;
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoints = (amount > _hitpoints) ? 0 : _hitpoints - amount;
	std::cout << "ScavTrap " << _name << " takes " << amount << " damage leaving it to " << _hitpoints << " hitpoints" << std::endl;
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