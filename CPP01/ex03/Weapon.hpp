/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:08:00 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/06 16:11:30 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

class Weapon
{
	private:
		std::string _type;
	public :
		Weapon(std::string type);
		~Weapon();
		std::string getType();
		void		setType(std::string type);
};