/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:08:00 by acaffard          #+#    #+#             */
/*   Updated: 2024/11/19 14:08:00 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("ClapTrap");
	ClapTrap claptrap2(claptrap);

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	claptrap2.attack("target");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);

	return 0;
}
