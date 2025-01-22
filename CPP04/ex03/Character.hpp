/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:03:39 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 12:05:40 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private :
		std::string	_name;
		AMateria			*_materias[4];
		AMateria			*_unequiped[1024];
		int					_unequiped_index;
	public :
		Character(std::string const &name);
		Character(const Character &copy);
		virtual ~Character();
		Character& operator=(const Character &copy);

		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};