/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:20:07 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 13:01:15 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "ERROR : You must input one string" << std::endl;
		return 1;
	}
	Harl	test;
	test.complain(av[1]);
	return 0;
}