/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:58:13 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 11:58:13 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	protected :
		std::string	_type;
	public :
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &copy);

		const std::string	&getType() const;
		virtual void	makeSound() const = 0;
};
