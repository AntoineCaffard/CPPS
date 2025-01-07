/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:41 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/07 11:53:46 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	ClapTrap trebours("Toma");
	std::cout << trebours << std::endl;
	trebours.takeDamage(9999);
	std::cout << trebours << std::endl;
	trebours.beRepaired(10);
	trebours.attack("Denis");
}