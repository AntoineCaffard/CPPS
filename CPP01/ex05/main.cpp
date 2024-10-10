/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:20:07 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 11:42:30 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl	test;
	test.complain("DEBUG");
	test.complain("WARNING");
	test.complain("INFO");
	test.complain("ERROR");
	test.complain("wololo");
	test.complain("ERROR");
}