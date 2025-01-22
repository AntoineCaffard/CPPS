/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:17:21 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 12:21:14 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice &copy);
		virtual ~Ice();
		Ice	&operator=(const Ice &copy);

		AMateria* clone() const;
		virtual void use(ICharacter& target);
};