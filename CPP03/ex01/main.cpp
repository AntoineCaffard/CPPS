/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:41 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/07 12:23:57 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main ()
{
	ClapTrap derey("Denis");
	std::cout << derey << std::endl;
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	derey.attack("Toma");
	std::cout << derey << std::endl;
	derey.takeDamage(9);
	derey.beRepaired(120);
	std::cout << derey << std::endl;
	derey.attack("Toma");
ScavTrap trebours("Toma");
	std::cout << trebours << std::endl;
	trebours.takeDamage(9999);
	std::cout << trebours << std::endl;
	trebours.beRepaired(10);
	trebours.attack("Denis");
}