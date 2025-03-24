/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:57:23 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/24 13:50:38 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include "easyfind.hpp"



int main (void)
{
	{
		std::srand(std::time(NULL));
		std::list<int>	int_list;
		try
		{
			fill(int_list, 100, 10);
			print_int(*(easyfind(int_list, 7)));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	{
		std::srand(std::time(NULL));
		std::vector<int>	int_vector;
		try
		{
			fill(int_vector, 100, 10);
			print_int(*(easyfind(int_vector, 7)));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	{
		std::srand(std::time(NULL));
		std::deque<int>	int_deque;
		try
		{
			fill(int_deque, 100, 10);
			print_int(*(easyfind(int_deque, 7)));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
}