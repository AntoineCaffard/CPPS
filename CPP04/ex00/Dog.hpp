/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:30:17 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 12:30:17 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &copy);

		void	makeSound() const;
};

std::ostream& operator<<(std::ostream &o, Dog const &dog);
