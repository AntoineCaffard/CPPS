/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:41 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/08 08:31:32 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
	std::cout << "--- CLAPTRAP TESTS ---" << std::endl;
	ClapTrap derey("Denis");
	std::cout << derey << std::endl;
	derey.takeDamage(9);
	std::cout << derey << std::endl;
	derey.beRepaired(120);
	std::cout << derey << std::endl;
	derey.attack("Toma");
	ClapTrap derey2(derey);
	std::cout << derey << std::endl;
	
	std::cout << "--- SCAVTRAP TESTS ---" << std::endl;
	ScavTrap trebours("Toma");
	trebours.guardGate();
	std::cout << trebours << std::endl;
	trebours.takeDamage(9999);
	std::cout << trebours << std::endl;
	trebours.beRepaired(10);
	trebours.attack("Denis");
	trebours.guardGate();
	ScavTrap trebours2(trebours);
	std::cout << trebours2 << std::endl;

	std::cout << "--- FRAGTRAP TESTS ---" << std::endl;
	FragTrap tebandam("Teddy");
	std::cout << tebandam << std::endl;
	tebandam.takeDamage(9999);
	std::cout << tebandam << std::endl;
	tebandam.beRepaired(10);
	tebandam.attack("Denis");
	tebandam.highFivesGuys();
	FragTrap tebandam2(tebandam);
	std::cout << tebandam2 << std::endl;
}