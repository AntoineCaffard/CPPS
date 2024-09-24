/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:30 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/24 15:03:11 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*michel;

	std::cout << "--- HEAP ALLOCATED ---" << std::endl << std::endl;
	michel = newZombie("Michel");
	michel->announce();
		std::cout << std::endl << "--- STACK ALLOCATED ---" << std::endl << std::endl;
	randomChump("Jackie");
	std::cout << std::endl;
	std::cout << "--- HEAP ALLOCATED DESTROYED ---" << std::endl << std::endl;
	delete michel;
}