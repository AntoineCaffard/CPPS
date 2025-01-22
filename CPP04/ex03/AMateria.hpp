/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:44:58 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 12:09:48 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ICharacter;

class AMateria
{
	protected :
		std::string _type;
	public :
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &copy);
		
		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};