/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:59:15 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/06 16:12:19 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	private :
		std::string _name;
		Weapon*		_weapon;
	public :
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon *weapon);
		void attack();
};
