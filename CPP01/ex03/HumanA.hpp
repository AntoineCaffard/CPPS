/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:17:17 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/06 16:02:35 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private :
		std::string _name;
		Weapon&		_weapon;
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
};