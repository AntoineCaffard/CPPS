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

class Animal
{
	protected :
		std::string	_type;
	public :
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &copy);

		const std::string	&getType() const;
		virtual void	makeSound() const;
};

std::ostream& operator<<(std::ostream &o, Animal const &animal);
