/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:59:26 by acaffard          #+#    #+#             */
/*   Updated: 2024/11/25 13:01:06 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : _name("FragTrap"), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "New FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "New FragTrap named " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " deleted" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " wants to high five BROOOOOO" << std::endl;
}