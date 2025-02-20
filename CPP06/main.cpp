/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:20:20 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/20 09:55:30 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !*argv[1])
	{
		std::cerr << "Error : You have to input one argument" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}