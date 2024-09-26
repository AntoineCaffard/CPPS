/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:30 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/26 14:50:48 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*michelHorde;
	Zombie	*jackieHorde;

	std::cout << "--- HEAP ALLOCATED ---" << std::endl << std::endl;
	michelHorde = zombieHorde(4, "Michel");
	jackieHorde = zombieHorde(4, "Jackie");
	for (int i = 0; i < 4; i++)
	{
		jackieHorde[i].announce();
		michelHorde[i].announce();
	}
	delete[] michelHorde;
	delete[] jackieHorde;

}