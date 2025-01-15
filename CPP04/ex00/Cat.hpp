/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:22:03 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 12:22:03 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();
		Cat &operator=(const Cat &copy);

		void	makeSound() const;
};

std::ostream& operator<<(std::ostream &o, Cat const &cat);
