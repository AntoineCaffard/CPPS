/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:08:00 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 10:22:02 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>


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