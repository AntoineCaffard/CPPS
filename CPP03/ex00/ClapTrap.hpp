/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:32:03 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/07 11:35:55 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	private :
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energypoints;
		unsigned int	_attackdamage;
	public :
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap &copy);
		
		std::string		getName();
		unsigned int	getHitPoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream &o, ClapTrap &claptrap);