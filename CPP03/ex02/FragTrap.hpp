/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:20:57 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/08 08:23:24 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();
		FragTrap& operator=(const FragTrap &copy);

		void highFivesGuys(void);
};

std::ostream& operator<<(std::ostream &o, FragTrap &fragtrap);