/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:23:58 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/08 08:32:45 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap : Default constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " : Name constructor called" << std::endl;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "FragTrap : Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " : Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &copy)
{
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energypoints = copy._energypoints;
	this->_attackdamage = copy._attackdamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << std::endl << _name << " : Hey there, awesome soul! ✋ High five incoming! Just like the perfect clap, our connection is right on point. Whether it’s for crushing goals or simply spreading good vibes, this high five is a symbol of our unstoppable energy. So, raise that hand, feel the power, and let's make the world a little brighter together! ✨🙌" << std::endl;
}

std::ostream& operator<<(std::ostream &o, FragTrap &fragtrap)
{
	o << std::endl << "------------------" << std::endl;
	o << "-----FRAGTRAP-----" << std::endl;
	o << "------------------" << std::endl;
	o << "name : " << fragtrap.getName() << std::endl;
	o << "hitpoints : " << fragtrap.getHitPoints() << std::endl;
	o << "energypoints : " << fragtrap.getEnergyPoints() << std::endl;
	o << "------------------" << std::endl;
	return (o);
}