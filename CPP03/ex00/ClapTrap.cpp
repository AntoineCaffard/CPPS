/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:52:34 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/08 08:15:01 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "ClapTrap : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "ClapTrap : Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap : Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &copy)
{
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energypoints = copy._energypoints;
	this->_attackdamage = copy._attackdamage;
	return *this;
}

std::string	ClapTrap::getName()
{
	return _name;
}

unsigned int	ClapTrap::getHitPoints()
{
	return _hitpoints;
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return _energypoints;
}

unsigned int	ClapTrap::getAttackDamage()
{
	return _attackdamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_hitpoints)
	{
		std::cout << "ClapTrap " << _name << " is completely brokem and cannot attack " << target << std::endl;
		return ;
	}
	if (!_energypoints)
	{
		std::cout << "ClapTrap " << _name << " does not have enough energy to attack " << target << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackdamage << " points of damage" << std::endl;
	_energypoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoints = (amount > _hitpoints) ? 0 : _hitpoints - amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage leaving it to " << _hitpoints << " hitpoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitpoints)
	{
		std::cout << "ClapTrap " << _name << " is completely broken and cannot repair itself "<< std::endl;
		return ;
	}
	if (!_energypoints)
	{
		std::cout << "ClapTrap " << _name << " does not have enough energy to repair itself" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs itself of " << amount << " hitpoints" << std::endl;
	_energypoints--;
	_hitpoints = (_hitpoints + amount > 10) ? 10 : _hitpoints + amount;
}

std::ostream& operator<<(std::ostream &o, ClapTrap &claptrap)
{
	o << std::endl << "------------------" << std::endl;
	o << "-----CLAPTRAP-----" << std::endl;
	o << "------------------" << std::endl;
	o << "name : " << claptrap.getName() << std::endl;
	o << "hitpoints : " << claptrap.getHitPoints() << std::endl;
	o << "energypoints : " << claptrap.getEnergyPoints() << std::endl;
	o << "------------------" << std::endl;
	return (o);
}