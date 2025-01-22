/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:13:00 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 12:21:33 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure &copy);
		virtual ~Cure();
		Cure	&operator=(const Cure &copy);

		AMateria* clone() const;
		virtual void use(ICharacter& target);
};
