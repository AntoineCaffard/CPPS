/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:01:17 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/07 12:16:51 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &copy);

		void guardGate();
};

std::ostream& operator<<(std::ostream &o, ScavTrap &scavtrap);