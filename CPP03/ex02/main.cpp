/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:08:00 by acaffard          #+#    #+#             */
/*   Updated: 2024/11/25 13:04:20 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("ClapTrap");
	ScavTrap scav ("wololo");
	FragTrap frag ("walala");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	scav.attack("Toma");
	scav.takeDamage(5);
	scav.beRepaired(3);
	scav.guardGate();
	frag.attack("Denis");
	frag.takeDamage(5);
	frag.beRepaired(3);
	frag.highFivesGuys();
	
	return 0;
}
