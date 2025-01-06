/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:18:11 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/06 14:10:28 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main ()
{
	Point a(-5 ,-3);
	Point b (-1, 7);
	Point c (4 , -1);
	{
		std::cout << "\e[1;33mPoint in the triangle with integer values :\e[0m"<< std::endl;
		Point point (-2, 1);
		std::cout << (bsp(a,b,c,point) ? "\e[1;32m[OK]\e[0m" : "\e[1;31m[KO]\e[0m") << std::endl;
	}
	{
		std::cout << "\e[1;33mPoint in the triangle with float values :\e[0m"<< std::endl;
		Point point ((float) 1.43, (float) 1.47);
		std::cout << (bsp(a,b,c,point) ? "\e[1;32m[OK]\e[0m" : "\e[1;31m[KO]\e[0m") << std::endl;
	}
	{
		std::cout << "\e[1;33mPoint is on an edge of the triangle :\e[0m"<< std::endl;
		Point point ((float) 0.96, (float) -1.68);
		std::cout << (bsp(a,b,c,point) ? "\e[1;32m[OK]\e[0m" : "\e[1;31m[KO]\e[0m") << std::endl;
	}

	{
		std::cout << "\e[1;33mPoint is a vertex of the triangle :\e[0m"<< std::endl;
		Point point ((float) 0.07, (float) -1.87);
		std::cout << (bsp(a,b,c,point) ? "\e[1;32m[OK]\e[0m" : "\e[1;31m[KO]\e[0m") << std::endl;
	}
	{
		std::cout << "\e[1;33mPoint is close to an edge of the triangle :\e[0m"<< std::endl;
		Point point ((float) -1.39, (float) 5.57);
		std::cout << (bsp(a,b,c,point) ? "\e[1;32m[OK]\e[0m" : "\e[1;31m[KO]\e[0m") << std::endl;
	}
	{
		std::cout << "\e[1;33mPoint is out of the triangle :\e[0m"<< std::endl;
		Point point ((float) 0, (float) -3);
		std::cout << (bsp(a,b,c,point) ? "\e[1;32m[OK]\e[0m" : "\e[1;31m[KO]\e[0m") << std::endl;
	}
}