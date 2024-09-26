/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:30:57 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/26 14:44:52 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*newHorde;

	newHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		newHorde[i].setName(name);
	return (newHorde);
}